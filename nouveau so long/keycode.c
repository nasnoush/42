/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keycode.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadahman <nadahman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 13:20:45 by nadahman          #+#    #+#             */
/*   Updated: 2024/11/26 13:59:44 by nadahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "GNL/get_next_line.h"
#include "printf/ft_printf.h"

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
