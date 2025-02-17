/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadahman <nadahman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 13:04:58 by nadahman          #+#    #+#             */
/*   Updated: 2024/11/25 11:53:08 by nadahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "printf/ft_printf.h"
#include "GNL/get_next_line.h"

int	count_line(char **map)
{
	int	count;

	count = 0;
	while (map[count] != NULL)
		count++;
	return (count);
}

/*size_t	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}*/
void	free_exit(char **map, void *mlx, t_assets *assets, void *window)
{
	free(map);
	mlx_destroy_window(mlx, window);
	free(mlx);
	free(assets);
}

int main (int argc, char **argv)
{
	void		*mlx;
	void		*window;
	t_assets	*assets;
	char		**map;
	int			largeur;
	int			longueur;

	assets = NULL;
	map = NULL;
	mlx = NULL;
	window = NULL;
	if (argc != 2)
	{
		ft_printf("Usage : ./so_long <map_file>");
		return (1);
	}
	map = charge_map(argv[1]);
	if (map == NULL || map[0] == NULL)
	{
		ft_printf("Erreur de chargement de la map");
		return (1);
	}
	largeur = ft_strlen(map[0]);
	longueur = count_line(map);
	mlx = mlx_init();
	window = mlx_new_window(mlx, (largeur - 1) * 32, longueur * 32, "So Long");
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
	mlx_hook(window, 2, 1L<<0, keyboard, assets);
	mlx_hook(window, 17, 1L<<17, close_window_x, assets);
	
	mlx_loop(mlx);
	return (0);
}

 