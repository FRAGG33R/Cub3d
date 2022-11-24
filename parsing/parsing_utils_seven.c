/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils_seven.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdrabi <hdrabi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 21:43:43 by atouhami          #+#    #+#             */
/*   Updated: 2022/04/06 14:47:27 by hdrabi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_isdigit(int character)
{
	if (character >= '0' && character <= '9')
		return (1);
	return (0);
}

int	check_colors(char *str)
{
	int	i;
	int	count;

	i = 1;
	count = 0;
	while (str[i] == ' ')
		i++;
	while (str[i])
	{
		if ((!ft_isdigit(str[i]) && str[i] != ',') || count > 2)
			return (1);
		if (str[i] == ',')
			count++;
		i++;
	}
	return (0);
}
