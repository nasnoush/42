/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deplacement.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadahman <nadahman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 16:26:55 by nadahman          #+#    #+#             */
/*   Updated: 2024/11/14 17:06:34 by nadahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "GNL/get_next_line.h"

void	deplacement(t_assets *assets, void *mlx, void *window, char **map)
{
	int	pos_x;
	int	pos_y;
	int	i;
	int	j;

	i = 0;
	j = 0;
	pos_x = -1;
	pos_y = -1;
	while (map[i])
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == 'P')
			{
				pos_y = i;
				pos_x = j;
				break ;
			}
			j++;
		}
		if (pos_x != -1 && pos_y != -1)
			break;
		i++;
	}
}




