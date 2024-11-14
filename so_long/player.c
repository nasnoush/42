/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadahman <nadahman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 13:54:03 by nadahman          #+#    #+#             */
/*   Updated: 2024/11/14 15:53:39 by nadahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "GNL/get_next_line.h"

void	aff_perso(t_assets *assets, void *mlx, void *window, char **map)
{
	int	y;
	int	x;
	int	i;
	int	j;

	i = 0;
	j = 0;
	x = 0;
	y = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == 'P')
			{
				x = i;
				y = j;
				break ;
			}
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(mlx, window, assets->sol1, y * 32, x * 32);
	mlx_put_image_to_window(mlx, window, assets->perso, y * 32, x * 32);
}
