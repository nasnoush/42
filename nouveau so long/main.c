/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadahman <nadahman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 13:04:58 by nadahman          #+#    #+#             */
/*   Updated: 2024/12/03 12:37:08 by nadahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GNL/get_next_line.h"
#include "printf/ft_printf.h"
#include "so_long.h"


int	main(int argc, char **argv)
{
	void		*mlx;
	void		*window;
	t_assets	*assets;
	char		**map;
	int			largeur;
	int			longueur;

	assets = malloc(sizeof(t_assets));
	if (!assets)
	{
		ft_printf("Erreur d'allocation de assets\n");
		return (1);
	}
	memset(assets, 0, sizeof(t_assets));
	if (argc != 2)
	{
		ft_printf("Usage : ./so_long <map_file>\n");
		free(assets);
		return (1);
	}
	assets->map = charge_map(argv[1], assets);
	if (assets->map == NULL || assets->map[0] == NULL)
	{
		ft_printf("Erreur de chargement de la map\n");
		free(assets);
		return (1);
	}
	map = assets->map;
	if (check_all_map_conditions(assets) == 0)
	{
		free_assets(assets);
		free_map(map);
		return (1);
	}
	largeur = ft_strlen(map[0]);
	longueur = count_line(map);
	mlx = mlx_init();
	window = mlx_new_window(mlx, (largeur) * 32, longueur * 32, "So Long");
	assets = load_assets(mlx);
	if (!assets)
		error("Failed to load assets");
	assets->mlx = mlx;
	assets->window = window;
	assets->map = map;
	assets->collectible = count_collect(map);
	position_perso(assets, map);
	place_assets(assets, map, mlx, window);
	aff_moove(assets, mlx, window);
	mlx_hook(window, 2, 1L << 0, keyboard, assets);
	mlx_loop(mlx);
	return (0);
}


