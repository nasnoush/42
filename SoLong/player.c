/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadahman <nadahman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 13:54:03 by nadahman          #+#    #+#             */
/*   Updated: 2024/12/12 10:23:32 by nadahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "GNL/get_next_line.h"
#include "printf/ft_printf.h"

void	aff_perso(t_assets *assets, void *mlx, void *window, char **map)
{
	int	y;
	int	x;
	int	i;
	int	j;

	i = 0;
	x = 0;
	y = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == 'P')
			{
				x = j;
				y = i;
				break ;
			}
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(mlx, window, assets->sol1, x * 32, y * 32);
	mlx_put_image_to_window(mlx, window, assets->perso, x * 32, y * 32);
}

void	aff_collect(t_assets *assets, void *mlx, void *window, char **map)
{
	int	y;
	int	x;
	int	i;
	int	j;

	i = 0;
	x = 0;
	y = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == 'C')
			{
				x = j;
				y = i;
				break ;
			}
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(mlx, window, assets->sol1, x * 32, y * 32);
	mlx_put_image_to_window(mlx, window, assets->collect, x * 32, y * 32);
}

int	strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}
