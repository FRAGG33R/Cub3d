/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarchil <abarchil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 14:44:23 by hdrabi            #+#    #+#             */
/*   Updated: 2022/04/10 19:51:54 by abarchil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	free_2d(unsigned int **buffer)
{
	int	i;

	i = -1;
	while (++i < SCREEN_H)
		free(buffer[i]);
	free(buffer);
	buffer = NULL;
	exit(1);
}

int	key_press(int keycode, t_all *all)
{
	t_key	*key;

	key = &all->key;
	if (keycode == 13)
		key->w = 1;
	if (keycode == 1)
		key->s = 1;
	if (keycode == 0)
		key->a = 1;
	if (keycode == 2)
		key->d = 1;
	if (keycode == 123)
		key->l = 1;
	if (keycode == 124)
		key->r = 1;
	if (keycode == 53)
		free_2d(all->ray->buffer);
	return (0);
}

int	key_release(int keycode, t_all *all)
{
	t_key	*key;

	key = &all->key;
	if (keycode == 13)
		key->w = 0;
	if (keycode == 1)
		key->s = 0;
	if (keycode == 0)
		key->a = 0;
	if (keycode == 2)
		key->d = 0;
	if (keycode == 123)
		key->l = 0;
	if (keycode == 124)
		key->r = 0;
	return (0);
}
