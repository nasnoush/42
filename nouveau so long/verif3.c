/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadahman <nadahman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 13:44:18 by nadahman          #+#    #+#             */
/*   Updated: 2024/12/05 13:54:16 by nadahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GNL/get_next_line.h"
#include "printf/ft_printf.h"
#include "so_long.h"

int	count_map_elements(t_assets *assets, char element)
{
	int	i;
	int	j;
	int	count;

	count = 0;
	i = 0;
	while (assets->map[i])
	{
		j = 0;
		while (assets->map[i][j] != '\0')
		{
			if (assets->map[i][j] == element)
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

void	count_collectibles(t_assets *assets)
{
	int	i;
	int	j;

	assets->item_count = 0;
	i = 0;
	while (i < assets->longueur)
	{
		j = 0;
		while (j < assets->largeur)
		{
			if (assets->map[i][j] == 'C')
			{
				assets->item_count++;
			}
			j++;
		}
		i++;
	}
}

int	count_map_height(char **map)
{
	int	height;

	height = 0;
	while (map[height])
		height++;
	return (height);
}
