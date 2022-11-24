/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdrabi <hdrabi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 22:40:59 by hdrabi            #+#    #+#             */
/*   Updated: 2022/04/08 17:24:34 by hdrabi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	texture_init(void *mlx, t_ray *ray, t_parsing parsing)
{
	ray->ceiling = parsing.color_ceiling;
	ray->floor = parsing.color_floor;
	load_img(mlx, &ray->t[0], parsing.no);
	load_img(mlx, &ray->t[1], parsing.so);
	load_img(mlx, &ray->t[2], parsing.ea);
	load_img(mlx, &ray->t[3], parsing.we);
}

static void	init_dir(char c, t_ray **ray)
{
	if (c == 'N' || c == 'S')
	{
		ray[0]->dir[X] = 1;
		ray[0]->dir[Y] = 0;
		ray[0]->plane[X] = 0;
		ray[0]->plane[Y] = -0.66 ;
		if (c == 'N')
		{
			ray[0]->dir[X] = -1;
			ray[0]->plane[Y] = 0.66 ;
		}
	}
	if (c == 'E' || c == 'W')
	{
		ray[0]->dir[X] = 0;
		ray[0]->dir[Y] = 1;
		ray[0]->plane[X] = 0.66;
		ray[0]->plane[Y] = 0;
		if (c == 'W')
		{
			ray[0]->dir[Y] = -1;
			ray[0]->plane[X] = -0.66;
		}
	}
}

static void	init_player(char	**map, float *x, float *y, char *c)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (ft_strchr("NEWS", map[i][j]))
			{
				*x = (float)i;
				*y = (float)j;
				*c = map[i][j];
				map[i][j] = '0';
			}
			j++;
		}
		i++;
	}
}

static void	ray_init(t_ray *ray, t_parsing parsing)
{
	char	c;
	int		i;

	init_player(parsing.map, &ray->pos[X], &ray->pos[Y], &c);
	init_dir(c, &ray);
	ray->buffer = malloc(SCREEN_H * sizeof(unsigned int *));
	(!ray->buffer && ft_error("Error: allocation failed\n", 1));
	i = -1;
	while (++i < SCREEN_H)
	{
		ray->buffer[i] = malloc(SCREEN_W * sizeof(unsigned int));
		(!ray->buffer[i] && ft_error("Error: allocation failed\n", 1));
	}
}

void	init_all(t_all *all, t_parsing parsing)
{
	t_ray	ray;
	t_win	win;

	all->map = parsing.map;
	ray_init(&ray, parsing);
	win.mlx = mlx_init();
	win.win = mlx_new_window(win.mlx, SCREEN_W, SCREEN_H, "cub3d");
	texture_init(win.mlx, &ray, parsing);
	draw_screen(&ray, &win, all->map);
	all->ray = &ray;
	all->win = &win;
	mlx_hook(win.win, 2, 1, key_press, all);
	mlx_hook(win.win, 3, 2, key_release, all);
	mlx_hook(win.win, 17, 0, &ft_close, NULL);
	mlx_loop_hook(win.mlx, smooth_move, all);
	mlx_loop(win.mlx);
}
