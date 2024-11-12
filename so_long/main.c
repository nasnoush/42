/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadahman <nadahman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 13:04:58 by nadahman          #+#    #+#             */
/*   Updated: 2024/11/12 13:55:20 by nadahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"

int main	(int argc, char **argv)
{
	void		*mlx;
	void		*window;
	t_assets	*assets;
	char		**map;

	if (argc != 2)
	{
		perror("Usage : ./so_long <map_file>");
		return (1);
	}
	mlx = mlx_init();
	if (mlx == NULL)
	{
		perror("Ca bug");
		return (1);
	}
	window = mlx_new_window(mlx, 800, 600, "So Long");
	if (window == NULL)
	{
		perror("Erreur de creation de fenetre");
		mlx_destroy(mlx);
		return (1);
	}
	assets = load_assets(mlx);
	if (assets == NULL)
	{
		perror("Erreur de chargement des assets");
		mlx_destroy_window(mlx, window);
		mlx_destroy(mlx);
		return (1);
	}
	map = load_map(argv[1]);
	if (map == NULL)
	{
		perror("Erreur de chargement de la map");
		mlx_destroy_window(mlx, window);
		mlx_destroy(mlx);
		free(assets);
		return (1);
	}
	place_assets(assets, map, mlx, window);
	mlx_loop(mlx);
	free(assets);
	mlx_destroy_window(mlx, window);
	mlx_destroy(mlx);
	return (0);
}
