/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadahman <nadahman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 12:13:32 by nadahman          #+#    #+#             */
/*   Updated: 2024/12/09 10:18:41 by nadahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GNL/get_next_line.h"
#include "printf/ft_printf.h"
#include "so_long.h"

int	main(int argc, char **argv)
{
	t_assets	*assets;

	if (argc != 2)
	{
		ft_printf("Error\nUsage: ./so_long <map_file>\n");
		return (1);
	}
	assets = malloc(sizeof(t_assets));
	if (!assets)
	{
		ft_printf("Error\nMemory allocation failed\n");
		return (1);
	}
	ft_memset(assets, 0, sizeof(t_assets));
	if (!check_map_loading(assets, argv[1])
		|| !init_mlx_window(assets, assets->map)
		|| !load_game_assets(assets)
		|| !validate_game_setup(assets))
	{
		free(assets);
		return (1);
	}
	run_game(assets);
	return (0);
}
