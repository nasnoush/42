/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deplacement2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadahman <nadahman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 12:25:31 by nadahman          #+#    #+#             */
/*   Updated: 2024/12/04 13:44:36 by nadahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GNL/get_next_line.h"
#include "so_long.h"
#include "printf/ft_printf.h"

int	check_map(t_assets *assets, int new_x, int new_y)
{
	if (!assets || !assets->map)
		return (0);
	if (new_y >= 0 && new_y < count_line(assets->map) && new_x >= 0
		&& new_x < (int)ft_strlen(assets->map[new_y]))
		return (1);
	return (0);
}

void	check_move(t_assets *assets, char next_pos)
{
	if (next_pos == '1')
		return ;
	if (next_pos == 'E' && assets->collectible > 0)
		return ;
}

void	end_game(t_assets *assets)
{
	aff_end_screen(assets->mlx, assets->window);
	ft_printf("Bien joué !\nTu as effectué %d mouvements\n",
		assets->count_moove);
	mlx_destroy_window(assets->mlx, assets->window);
	free_map(assets->map);
	free(assets);
	exit(0);
}

void	actualisation_deplacement(t_assets *assets, int new_x, int new_y)
{
	char	next_pos;

	if (!check_map(assets, new_x, new_y))
		return ;
	next_pos = assets->map[new_y][new_x];
	check_move(assets, next_pos);
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
		ft_printf("Nombre de mouvement : %d\n", assets->count_moove);
		actualisation_map(assets, assets->mlx, assets->window);
	}
	if (next_pos == 'E' && assets->collectible == 0)
		end_game(assets);
}
