/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadahman <nadahman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 13:39:17 by nadahman          #+#    #+#             */
/*   Updated: 2024/12/03 18:12:05 by nadahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	**ft_map_dup(char **map)
{
	char	**dup;
	int		i;
	int		height;

	if (!map)
		return (NULL);
	height = count_line(map);
	dup = (char **)malloc(sizeof(char *) * (height + 1));
	if (!dup)
		return (NULL);
	i = 0;
	while (i < height)
	{
		dup[i] = strdup(map[i]);
		if (!dup[i])
		{
			while (--i >= 0)
				free(dup[i]);
			free(dup);
			return (NULL);
		}
		i++;
	}
	dup[i] = NULL;
	return (dup);
}


static int	flood_fill(t_assets *assets, int x, int y, char **visited)
{
	if (x < 0 || x >= assets->longueur
		|| y < 0 || y >= assets->largeur
		|| visited[y][x] == '1'
		|| assets->map[y][x] == '1')
		return (0);
	if (assets->map[y][x] == 'E')
		assets->exit_count++;
	if (assets->map[y][x] == 'C')
		assets->collectible++;
	visited[y][x] = '1';
	flood_fill(assets, x + 1, y, visited);
	flood_fill(assets, x - 1, y, visited);
	flood_fill(assets, x, y + 1, visited);
	flood_fill(assets, x, y - 1, visited);
	return (1);
}

int	check_map_validity(t_assets *assets)
{
	char	**visited;
	int		i;

	assets->collectible = count_collectibles(assets);
	visited = ft_map_dup(assets->map);
	if (!visited)
		return (0);
	assets->exit_count = 0;
	assets->collectible = 0;
	flood_fill(assets, assets->pos_x, assets->pos_y, visited);
	i = 0;
	while (visited[i])
		free(visited[i++]);
	free(visited);
	return (assets->exit_count > 0
		&& assets->collectible == assets->item_count);
}

