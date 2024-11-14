/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deplacement.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadahman <nadahman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 16:26:55 by nadahman          #+#    #+#             */
/*   Updated: 2024/11/14 18:24:04 by nadahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "GNL/get_next_line.h"

void	position_perso(t_assets *assets, char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == 'P')
			{
				assets->pos_y = i;
				assets->pos_x = j;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	actualisation_deplacement(t_assets *assets, int new_x, int new_y)
{
if ((size_t)new_y < (size_t)count_line(assets->map) && (size_t)new_x < (size_t)ft_strlen(assets->map[0]))
	{
		if (assets->map[new_y][new_x] == '0')
		{
			assets->map[assets->pos_y][assets->pos_x] = '0';
			assets->map[new_y][new_x] = 'P';
			assets->pos_x = new_x;
			assets->pos_y = new_y;
		}
	}
}

int	depl_haut(int keycode, t_assets *assets)
{
	if (keycode == 87)
		actualisation_deplacement(assets, assets->pos_x, assets->pos_y - 1);
	return (0);
}

void	actualisation_map(t_assets *assets, void *mlx, void *window)
{
	place_assets(assets, assets->map, mlx, window);
	aff_perso(assets, mlx, window, assets->map);
}






