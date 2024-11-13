/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadahman <nadahman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 09:58:18 by nadahman          #+#    #+#             */
/*   Updated: 2024/11/13 14:07:05 by nadahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "GNL/get_next_line.h"

t_assets	*load_assets(void *mlx)
{
	t_assets	*assets;
	int			width;
	int			height;

	assets = malloc(sizeof(t_assets));
	if (assets == NULL)
		return (NULL);
	assets->sol1 = mlx_xpm_file_to_image(mlx, "assets/sol1.xpm", &width, &height);
	assets->sol2 = mlx_xpm_file_to_image(mlx, "assets/sol2.xpm", &width, &height);
	assets->mur = mlx_xpm_file_to_image(mlx, "assets/mur.xpm", &width, &height);
	assets->exit = mlx_xpm_file_to_image(mlx, "assets/exit.xpm", &width, &height);
	assets->contour = mlx_xpm_file_to_image(mlx, "assets/contour.xpm", &width, &height);
	
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
			recup_asset = def_assets_to_char(map[x][y], assets);
			if (recup_asset != NULL)
				mlx_put_image_to_window(mlx, window, recup_asset, y * 32, x * 32);
			if (map[x][y] == 'M')
			{
				mlx_put_image_to_window(mlx, window, assets->contour, y * 32, x * 32);
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
	else if (i == '1')
		return (assets->mur);
	else if (i == '2')
		return (assets->sol2);
	else if (i == 'C')
		return (assets->collect);
	else if (i == 'E')
		return (assets->exit);
	else if (i == 'P')
		return (assets->perso);
	else if (i == 'M')
		return (assets->contour);
	else
	{
		/*perror("Caractere non reconnu");*/
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
	close (fd);
	map[row] = NULL;
	return (map);
}
