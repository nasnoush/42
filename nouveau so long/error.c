/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadahman <nadahman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 10:16:19 by nadahman          #+#    #+#             */
/*   Updated: 2024/12/10 12:35:31 by nadahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "GNL/get_next_line.h"
#include "printf/ft_printf.h"

void	error(char *str)
{
	perror(str);
	exit(EXIT_FAILURE);
}

int	verif_assets(t_assets *assets)
{
	if (!assets || !assets->map)
	{
		return (0);
	}
	return (1);
}

int	count_line(char **map)
{
	int	count;

	count = 0;
	if (!map)
		return (0);
	while (map[count] != NULL)
		count++;
	return (count);
}

void	free_exit(char **map, void *mlx, t_assets *assets, void *window)
{
	free(map);
	mlx_destroy_window(mlx, window);
	free(mlx);
	free(assets);
}

void	*free_assets(t_assets *assets)
{
	if (!assets)
		return (NULL);
	if (assets->mlx)
	{
		if (assets->sol1)
			mlx_destroy_image(assets->mlx, assets->sol1);
		if (assets->exit)
			mlx_destroy_image(assets->mlx, assets->exit);
		if (assets->contour)
			mlx_destroy_image(assets->mlx, assets->contour);
		if (assets->perso)
			mlx_destroy_image(assets->mlx, assets->perso);
		if (assets->collect)
			mlx_destroy_image(assets->mlx, assets->collect);
		if (assets->window)
			mlx_destroy_window(assets->mlx, assets->window);
		free(assets->mlx);
	}
	if (assets->map)
		free_map(assets->map);
	free(assets);
	return (NULL);
}
