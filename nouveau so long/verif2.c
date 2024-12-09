/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+        
	+:+     */
/*   By: nadahman <nadahman@student.42.fr>          +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+  
	+#+           */
/*   Created: 2024/12/05 12:36:09 by nadahman          #+#    #+#             */
/*   Updated: 2024/12/05 12:36:09 by nadahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GNL/get_next_line.h"
#include "printf/ft_printf.h"
#include "so_long.h"

void	initialize_map_dimensions(t_assets *assets)
{
	verif_assets(assets);
	assets->longueur = 0;
	while (assets->map[assets->longueur])
		assets->longueur++;
	assets->largeur = 0;
	if (assets->longueur > 0)
		assets->largeur = ft_strlen(assets->map[0]);
}

static void	initialize_start_position(t_assets *assets)
{
	int	i;
	int	j;

	i = 0;
	verif_assets(assets);
	while (i < assets->longueur)
	{
		j = 0;
		while (j < assets->largeur)
		{
			if (assets->map[i][j] == 'P')
			{
				assets->pos_x = j;
				assets->pos_y = i;
				return ;
			}
			j++;
		}
		i++;
	}
}

static char	**ft_map_dup(char **map)
{
	char	**dup;
	int		i;
	int		height;

	if (!map)
		return (NULL);
	height = count_map_height(map);
	dup = (char **)malloc(sizeof(char *) * (height + 1));
	if (!dup)
		return (NULL);
	i = 0;
	while (i < height)
	{
		dup[i] = ft_strdup(map[i]);
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
	verif_assets(assets);
	if (x < 0 || x >= assets->largeur || y < 0 || y >= assets->longueur
		|| visited[y][x] == 'V' || assets->map[y][x] == '1')
		return (0);
	visited[y][x] = 'V';
	if (assets->map[y][x] == 'E')
		assets->exit_count++;
	if (assets->map[y][x] == 'C')
		assets->collectible++;
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

	verif_assets(assets);
	initialize_map_dimensions(assets);
	initialize_start_position(assets);
	count_collectibles(assets);
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
