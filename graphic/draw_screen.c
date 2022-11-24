/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_screen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdrabi <hdrabi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 00:02:30 by hdrabi            #+#    #+#             */
/*   Updated: 2022/04/08 16:44:19 by hdrabi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	pixel_put(t_win *win, int x, int y, int color)
{
	char	*dst;

	dst = win->addr + (x * (win->bits_per_pixel / 8) + y * win->size_line);
	*(int *)dst = color;
}

int	ft_verline(t_win *win, unsigned int **buffer, int mode)
{
	int	i;
	int	j;

	i = -1;
	while (++i < SCREEN_H)
	{
		j = -1;
		while (++j < SCREEN_W)
		{
			if (mode)
				pixel_put(win, j, i, buffer[i][j]);
			else
				buffer[i][j] = 0;
		}
	}
	return (1);
}

void	dda_and_draw(t_ray *ray, t_win *win, char **map, int x)
{
	vars_init(ray, x);
	initial_dist(ray);
	wall_collision(ray, map);
	initial_color(ray);
	initial_color_2(win, ray);
}

void	draw_screen(t_ray *ray, t_win *win, char **map)
{
	int	x;

	win->img = mlx_new_image(win->mlx, SCREEN_W, SCREEN_H);
	win->addr = mlx_get_data_addr(win->img, &win->bits_per_pixel, \
	&win->size_line, &win->endian);
	x = -1;
	while (++x < SCREEN_W)
	{
		win->x = x;
		dda_and_draw(ray, win, map, x);
	}
	(ft_verline(win, ray->buffer, 1) && ft_verline(win, ray->buffer, 0));
	mlx_put_image_to_window(win->mlx, win->win, win->img, 0, 0);
	mlx_destroy_image(win->mlx, win->img);
}

unsigned int	get_color(t_texture *t, int x, int y)
{
	char	*ptr;
	int		pixel;

	pixel = y * t->sl + x * 4;
	ptr = t->addr + pixel;
	return ((((unsigned char)ptr[2]) << 16)
		+ (((unsigned char)ptr[1]) << 8) + ((unsigned char)ptr[0]));
}
