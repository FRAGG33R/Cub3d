/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarchil <abarchil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 23:04:16 by hdrabi            #+#    #+#             */
/*   Updated: 2022/04/10 07:19:51 by abarchil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_error(char *str, int exit_status)
{
	write(2, str, ft_strlen(str));
	exit(exit_status);
	return (exit_status);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	if ((char)c == '\0')
		return ((char *)(s + ft_strlen(s)));
	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i++;
	}
	return (NULL);
}

void	load_img(void *mlx, t_texture	*t, char *filename)
{
	int	w;
	int	h;

	t->img = mlx_xpm_file_to_image(mlx, filename, &w, &h);
	if (!t->img)
		return (printf("invalid texture files"), exit(1));
	t->addr = mlx_get_data_addr(t->img, &t->bpp, &t->sl, &t->en);
}

float	f_abs(float n)
{
	if (n >= 0)
		return (n);
	return (-n);
}

int	ft_close(void)
{
	exit(1);
	return (0);
}
