/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarchil <abarchil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 22:17:36 by hdrabi            #+#    #+#             */
/*   Updated: 2022/04/10 19:51:34 by abarchil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char *av[])
{
	t_all		all;
	t_parsing	parsing;

	all.key.move_speed = 0.05;
	all.key.rot_speed = 0.05;
	main_parse(ac, av, &parsing);
	init_all(&all, parsing);
	free_parsing(&parsing);
	return (0);
}
