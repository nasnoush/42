/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keycode.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadahman <nadahman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 13:20:45 by nadahman          #+#    #+#             */
/*   Updated: 2024/11/25 10:52:41 by nadahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "GNL/get_next_line.h"
#include "printf/ft_printf.h"

#define KEY_ESC 65307
#define KEY_W 119
#define KEY_S 115
#define KEY_A 97
#define KEY_D 100

int	depl_haut(int keycode, t_assets *assets)
{
	if (keycode == KEY_W)
	{
		actualisation_deplacement(assets, assets->pos_x, assets->pos_y - 1);
	}
	return (0);
}

int	depl_bas(int keycode, t_assets *assets)
{
	if (keycode == KEY_S)
	{
		actualisation_deplacement(assets, assets->pos_x, assets->pos_y + 1);
	}
	return (0);
}

int	depl_left(int keycode, t_assets *assets)
{
	if (keycode == KEY_A)
	{
		actualisation_deplacement(assets, assets->pos_x - 1, assets->pos_y);
	}
	return (0);
}

int	depl_right(int keycode, t_assets *assets)
{
	if (keycode == KEY_D)
	{
		actualisation_deplacement(assets, assets->pos_x + 1, assets->pos_y);
	}
	return (0);
}

int	close_window(int keycode, t_assets *assets)
{
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(assets->mlx, assets->window);
		free_map(assets->map);
		free(assets);
		exit(0);
	}
	return (0);
}

int	close_window_x(t_assets *assets)
{
	mlx_destroy_window(assets->mlx, assets->window);
	free_map(assets->map);
	free(assets);
	exit(0);
	return (0);
}