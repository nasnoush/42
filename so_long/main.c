/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadahman <nadahman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 13:04:58 by nadahman          #+#    #+#             */
/*   Updated: 2024/11/18 13:11:23 by nadahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
		perror("Usage : ./so_long <map_file>");
		return (1);
	}
	map = charge_map(argv[1]);
	if (map == NULL || map[0] == NULL)
	{
		perror("Erreur de chargement de la map");
		mlx_destroy_window(mlx, window);
		return (1);
	}
	largeur = ft_strlen(map[0]);
	longueur = count_line(map);
	mlx = mlx_init();
	window = mlx_new_window(mlx, (largeur - 1) * 32, longueur * 32, "So Long");
	assets = load_assets(mlx);
	mlx_key_hook(window, keyboard,  assets);
	/*actualisation_map(assets, mlx, window);*/
	place_assets(assets, map, mlx, window);
	aff_perso(assets, mlx, window, map);
	mlx_loop(mlx);
	return (0);
}

 