/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadahman <nadahman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 09:58:18 by nadahman          #+#    #+#             */
/*   Updated: 2024/11/20 14:03:18 by nadahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GNL/get_next_line.h"
#include "so_long.h"

t_assets	*load_assets(void *mlx)
{
	t_assets	*assets;
	int			largeur;
	int			longueur;

	assets = malloc(sizeof(t_assets));
	if (assets == NULL)
		return (NULL);
	assets->sol1 = mlx_xpm_file_to_image(mlx, "assets/sol1.xpm", &largeur,
			&longueur);
	assets->sol2 = mlx_xpm_file_to_image(mlx, "assets/sol2.xpm", &largeur,
			&longueur);
	assets->mur = mlx_xpm_file_to_image(mlx, "assets/mur.xpm", &largeur,
			&longueur);
	assets->exit = mlx_xpm_file_to_image(mlx, "assets/exit.xpm", &largeur,
			&longueur);
	assets->contour = mlx_xpm_file_to_image(mlx, "assets/contour.xpm", &largeur,
			&longueur);
	assets->perso = mlx_xpm_file_to_image(mlx, "assets/perso.xpm", &largeur,
			&longueur);
	assets->collect = mlx_xpm_file_to_image(mlx, "assets/collect.xpm", &largeur,
			&longueur);
	assets->mlx = mlx;
	assets->count_moove = 0;
	return (assets);
}

void	place_assets(t_assets *assets, char **map, void *mlx, void *window)
{
	int		x;
	int		y;
	void	*recup_asset;

	x = 0;
	while (map[x] != NULL)
	{
		y = 0;
		while (map[x][y] != '\0')
		{
			mlx_put_image_to_window(mlx, window, assets->sol1, y * 32, x * 32);
			y++;
		}
		x++;
	}
	x = 0;
	while (map[x] != NULL)
	{
		y = 0;
		while (map[x][y] != '\0')
		{
			if (map[x][y] != '0' && map[x][y] != 'P')
			{
				recup_asset = def_assets_to_char(map[x][y], assets);
				if (recup_asset != NULL)
					mlx_put_image_to_window(mlx, window, recup_asset, y * 32, x
						* 32);
			}
			y++;
		}
		x++;
	}
}

void	*def_assets_to_char(char i, t_assets *assets)
{
	if (i == '0')
		return (assets->sol1);
	else if (i == 'C')
		return (assets->collect);
	else if (i == 'E')
		return (assets->exit);
	else if (i == 'P')
		return (assets->perso);
	else if (i == '1')
		return (assets->contour);
	else
	{
		return (NULL);
	}
}

char	**charge_map(const char *filename)
{
	int		fd;
	char	**map;
	char	*line;
	int		row;

	fd = open(filename, O_RDONLY);
	map = NULL;
	row = 0;
	if (fd < 0)
		return (NULL);
	map = malloc(sizeof(char *) * MAX_LINES);
	if (map == NULL)
		return (NULL);
	while ((line = get_next_line(fd)) != NULL)
	{
		map[row] = line;
		row++;
		if (row >= MAX_LINES)
			break ;
	}
	close(fd);
	map[row] = NULL;
	return (map);
}
