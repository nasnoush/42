/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deplacement.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadahman <nadahman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 16:26:55 by nadahman          #+#    #+#             */
/*   Updated: 2024/11/20 14:02:00 by nadahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GNL/get_next_line.h"
#include "so_long.h"

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

int	count_collect(char **map)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 0;
	count = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == 'C')
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

/*void	actualisation_deplacement(t_assets *assets, int new_x, int new_y)
{
	char	assets_actuel;
	int		y;
	int		x;
	char	next_pos;
	int		y;
	int		x;

	assets_actuel = assets->map[assets->pos_y][assets->pos_x];
	if (assets_actuel == '0' || assets_actuel == 'P' || assets_actuel == 'E')
	{
		if (assets_actuel == 'C')
		{
			assets->collect--;
			assets->map[assets->pos_y][assets->pos_x] = '0';
		}
		if (assets->collect == 0)
		{
			y = 0;
			while (assets->map[y] != NULL)
			{
				x = 0;
				while (assets->map[y][x] != '\0')
				{
					if (assets->map[y][x] == 'E')
						exit(0);
				x++;
				}
			y++;
			}
		}
		if (assets_actuel == 'P')
			assets->map[assets->pos_y][assets->pos_x] = '0';
		else if (assets_actuel == 'E')
			assets->map[assets->pos_y][assets->pos_x] = 'E';
	}
	if (!assets || !assets->map)
		return ;
	if ((size_t)new_y >= 0 && (size_t)new_y < (size_t)count_line(assets->map) &&
		(size_t)new_x >= 0
			&& (size_t)new_x < (size_t)ft_strlen(assets->map[new_y]))
	{
		if (assets->map[new_y][new_x] == '0' || assets->map[new_y][new_x] == 'E'
			|| assets->map[new_y][new_x] == 'E')
		{
			if (assets->map[new_y][new_x] == '0')
				exit(0);
			assets->map[assets->pos_y][assets->pos_x] = '0';
			assets->map[new_y][new_x] = 'P';
			assets->pos_x = new_x;
			assets->pos_y = new_y;
			actualisation_map(assets, assets->mlx, assets->window);
		}
	}
}*/
void	actualisation_deplacement(t_assets *assets, int new_x, int new_y)
{
	char	next_pos;

	if (!assets || !assets->map)
		return ;
	if (new_y >= 0 && new_y < count_line(assets->map)
		&& new_x >= 0
		&& new_x < (int)ft_strlen(assets->map[new_y]))
	{
		next_pos = assets->map[new_y][new_x];
		if (next_pos == '1')
			return ;
		if (next_pos == 'E' && assets->collectible > 0)
			return ;
		if (next_pos == '0' || next_pos == 'C')
		{
			assets->map[assets->pos_y][assets->pos_x] = '0';
			if (next_pos == 'C')
				assets->collectible--;
			assets->map[new_y][new_x] = 'P';
			assets->pos_x = new_x;
			assets->pos_y = new_y;
			assets->count_moove++;
			aff_moove(assets, assets->mlx, assets->window);
			printf("Nombre de mouvement : %d\n", assets->count_moove);
			actualisation_map(assets, assets->mlx, assets->window);
		}
		if (next_pos == 'E' && assets->collectible == 0)
		{
			printf("Bien joué !\nTu as effectué %d mouvements\n",
				assets->count_moove);
			mlx_destroy_window(assets->mlx, assets->window);
			free_map(assets->map);
			free(assets);
			exit(0);
		}
	}
}

int	depl_haut(int keycode, t_assets *assets)
{
	if (keycode == 13)
	{
		actualisation_deplacement(assets, assets->pos_x, assets->pos_y - 1);
	}
	return (0);
}

int	depl_bas(int keycode, t_assets *assets)
{
	if (keycode == 1)
	{
		actualisation_deplacement(assets, assets->pos_x, assets->pos_y + 1);
	}
	return (0);
}

int	depl_left(int keycode, t_assets *assets)
{
	if (keycode == 0)
	{
		actualisation_deplacement(assets, assets->pos_x - 1, assets->pos_y);
	}
	return (0);
}

int	depl_right(int keycode, t_assets *assets)
{
	if (keycode == 2)
	{
		actualisation_deplacement(assets, assets->pos_x + 1, assets->pos_y);
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
	if (!assets || !mlx || !window || !assets->map)
		return ;
	mlx_clear_window(mlx, window);
	place_assets(assets, assets->map, mlx, window);
	aff_perso(assets, mlx, window, assets->map);
	aff_moove(assets, mlx, window);
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
