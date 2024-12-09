/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadahman <nadahman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 13:04:58 by nadahman          #+#    #+#             */
/*   Updated: 2024/12/09 12:05:35 by nadahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GNL/get_next_line.h"
#include "printf/ft_printf.h"
#include "so_long.h"

int	check_map_loading(t_assets *assets, char *map_file)
{
	assets->map = charge_map(map_file, assets);
	if (assets->map == NULL || assets->map[0] == NULL)
	{
		ft_printf("Error\nMap loading failed\n");
		return (0);
	}
	return (1);
}

int	init_mlx_window(t_assets *assets, char **map)
{
	int	largeur;
	int	longueur;

	largeur = ft_strlen(map[0]);
	longueur = count_line(map);
	assets->mlx = mlx_init();
	if (!assets->mlx)
	{
		ft_printf("Error\nMLX initialization failed\n");
		return (0);
	}
	assets->window = mlx_new_window(assets->mlx, largeur * 32,
			longueur * 32, "So Long");
	if (!assets->window)
	{
		ft_printf("Error\nWindow creation failed\n");
		return (0);
	}
	return (1);
}

int	load_game_assets(t_assets *assets)
{
	t_assets	*tmp_assets;

	tmp_assets = load_assets(assets->mlx);
	if (!tmp_assets)
	{
		ft_printf("Error\nAssets loading failed\n");
		return (0);
	}
	assets->sol1 = tmp_assets->sol1;
	assets->sol2 = tmp_assets->sol2;
	assets->mur = tmp_assets->mur;
	assets->contour = tmp_assets->contour;
	assets->collect = tmp_assets->collect;
	assets->perso = tmp_assets->perso;
	assets->exit = tmp_assets->exit;
	assets->collectible = count_collect(assets->map);
	free(tmp_assets);
	return (1);
}

int	validate_game_setup(t_assets *assets)
{
	if (!assets)
        return (0);
	if (check_all_map_conditions(assets) == 0)
	{
		return (0);
	}
	return (1);
}

void	run_game(t_assets *assets)
{
	position_perso(assets);
	place_assets(assets, assets->map, assets->mlx, assets->window);
	aff_moove(assets, assets->mlx, assets->window);
	mlx_hook(assets->window, 2, 1L << 0, keyboard, assets);
	mlx_hook(assets->window, 17, 0, close_window_x, assets);
	mlx_loop(assets->mlx);
}
