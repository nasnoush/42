/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deplacement.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadahman <nadahman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 16:26:55 by nadahman          #+#    #+#             */
/*   Updated: 2024/12/04 12:45:25 by nadahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GNL/get_next_line.h"
#include "printf/ft_printf.h"
#include "so_long.h"

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	position_perso(t_assets *assets)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (assets == NULL || assets->map == NULL)
		return ;
	while (assets->map[i])
	{
		j = 0;
		while (assets->map[i][j] != '\0')
		{
			if (assets->map[i][j] == 'P')
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

int	count_collect(char **map)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 0;
	count = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == 'C')
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

int	count_exit(char **map)
{
	int	x;
	int	y;
	int	exit_count;

	exit_count = 0;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'E')
				exit_count++;
			x++;
		}
		y++;
	}
	return (exit_count);
}

void	actualisation_map(t_assets *assets, void *mlx, void *window)
{
	if (!assets || !mlx || !window || !assets->map)
		return ;
	mlx_clear_window(mlx, window);
	place_assets(assets, assets->map, mlx, window);
	aff_perso(assets, mlx, window, assets->map);
	aff_moove(assets, mlx, window);
}
