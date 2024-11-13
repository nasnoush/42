/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadahman <nadahman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 13:04:58 by nadahman          #+#    #+#             */
/*   Updated: 2024/11/13 13:44:51 by nadahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main (int argc, char **argv)
{
	void		*mlx;
	void		*window;
	t_assets	*assets;
	char		**map;

	assets = NULL;
	if (argc != 2)
	{
		perror("Usage : ./so_long <map_file>");
		return (1);
	}
	mlx = mlx_init();
	window = mlx_new_window(mlx, 1080, 550, "So Long");
	assets = load_assets(mlx);
	map = charge_map(argv[1]);
	if (map == NULL)
	{
		perror("Erreur de chargement de la map");
		mlx_destroy_window(mlx, window);
		return (1);
	}
	place_assets(assets, map, mlx, window);
	mlx_loop(mlx);
	return (0);
}
