/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadahman <nadahman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 09:58:18 by nadahman          #+#    #+#             */
/*   Updated: 2024/11/12 14:04:59 by nadahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"
#include "GNL/get_next_line.h"

t_assets	*load_assets(void *mlx)
{
	t_assets	*assets;
	int			width;
	int			height;

	assets = malloc(sizeof(t_assets));
	if (assets == NULL)
		return (NULL);
	assets->sol1 = mlx_png_file_to_image(mlx, "assets/sol1.png", &width, &height);
	assets->sol2 = mlx_png_file_to_image(mlx, "assets/sol2.png", &width, &height);
	assets->mur = mlx_png_file_to_image(mlx, "assets/mur.png", &width, &height);
	assets->exit = mlx_png_file_to_image(mlx, "assets/exit.png", &width, &height);
	assets->perso = mlx_png_file_to_image(mlx, "assets/perso.png", &width, &height);
	assets->collect = mlx_png_file_to_image(mlx, "assets/collect.png", &width, &height);
	return (assets);
}

void	place_assets(t_assets *assets, char **map, void *mlx, void *window)
{
	int		x;
	int		y;
	void	*recup_asset;

	x = 0;
	while (map[x] != NULL && map[x][y] !- '\0')
	{
		y = 0;
		while (map[x][y] != '\0')
		{
			recup_asset = def_assets_to_char(map[x][y], assets);
			if (recup_asset != NULL)
				mlx_put_image_to_window(mlx, window, recup_asset, y * 32, x * 32);
			y++;
		}
	x++;
	}
}

void	*def_assets_to_char(char i, t_assets *assets)
{
	if (i == '0')
		return (assets->sol1);
	if (i == '1')
		return (assets->mur);
	if (i == '2')
		return (assets->sol2);
	if (i == 'C')
		return (assets->collect);
	if (i == 'E')
		return (assets->exit);
	if (i == 'P')
		return (assets->perso);
	else
	{
		perror("Caractere non reconnu");
		return (NULL);
	}
}

char	**load_map(const char *filename)
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
	}
	close (fd);
	free(map);
	return (map);
}