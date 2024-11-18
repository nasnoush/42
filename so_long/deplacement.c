/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deplacement.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 16:26:55 by nadahman          #+#    #+#             */
/*   Updated: 2024/11/18 19:01:39 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "GNL/get_next_line.h"

void	position_perso(t_assets *assets, char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (assets == NULL || map == NULL)
		return ;
	while (map[i])
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == 'P')
			{
				assets->pos_y = i;
				assets->pos_x = j;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	actualisation_deplacement(t_assets *assets, int new_x, int new_y)
{
	if (!assets || !assets->map)
		return ;
	if (new_y >= 0 && new_y < count_line(assets->map) &&
		new_x >= 0 && new_x < ft_strlen(assets->map[new_y]))
	{
		if (assets->map[new_y][new_x] == '0')
		{
			assets->map[assets->pos_y][assets->pos_x] = '0';
			assets->map[new_y][new_x] = 'P';
			assets->pos_x = new_x;
			assets->pos_y = new_y;
		}
	}
}

int	depl_haut(int keycode, t_assets *assets)
{
	int	new_x;
	int	new_y;
	if (keycode == 13)
	{
		new_x = assets->pos_x;
		new_y = assets->pos_y - 1;
		actualisation_deplacement(assets, new_x, new_y);
       	actualisation_map(assets, assets->mlx, assets->window);
	}
	return (0);
}

int	depl_bas(int keycode, t_assets *assets)
{
	int	new_x;
	int	new_y;

	if (keycode == 1)
	{
		new_x = assets->pos_x;
		new_y = assets->pos_y + 1;
		actualisation_deplacement(assets, new_x, new_y);
        actualisation_map(assets, assets->mlx, assets->window); 
	}
	return (0);
}

int	depl_left(int keycode, t_assets *assets)
{
	int	new_x;
	int	new_y;
	
	if (keycode == 0)
	{
		new_x = assets->pos_x - 1;
		new_y = assets->pos_y;
		actualisation_deplacement(assets, new_x, new_y);
		actualisation_map(assets, assets->mlx, assets->window);
	}
	return (0);
}

int	depl_right(int keycode, t_assets *assets)
{
	int	new_x;
	int	new_y;
	
	if (keycode == 2)
	{
		new_x = assets->pos_x + 1;
		new_y = assets->pos_y;
		actualisation_deplacement(assets, new_x, new_y);
		actualisation_map(assets, assets->mlx, assets->window);
	}
	return (0);
}

int	close_window(int keycode, t_assets *assets)
{
	if (keycode == 53)
	{
		mlx_destroy_window(assets->mlx, assets->window);
		free_map(assets->map);
		free(assets);
		exit(0);
	}
	return (0);
}


void	actualisation_map(t_assets *assets, void *mlx, void *window)
{
	place_assets(assets, assets->map, mlx, window);
	aff_perso(assets, mlx, window, assets->map);
}

int	keyboard(int keycode, t_assets *assets)
{
	if (keycode == 13)
		depl_haut(keycode, assets);
	else if (keycode == 1)
		depl_bas(keycode, assets);
	else if (keycode == 0)
		depl_left(keycode, assets);
	else if (keycode == 2)
		depl_right(keycode, assets);
	else if (keycode == 53)
		close_window(keycode, assets);
	return (0);
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;	
	}
	free(map);
}




