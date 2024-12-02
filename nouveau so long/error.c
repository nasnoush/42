/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadahman <nadahman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 10:16:19 by nadahman          #+#    #+#             */
/*   Updated: 2024/12/02 12:53:15 by nadahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "GNL/get_next_line.h"
#include "printf/ft_printf.h"

void	error(char *str)
{
	perror(str);
	exit(EXIT_FAILURE);
}

int	verif_assets(t_assets *assets)
{
	if (!assets || !assets->map)
	{
		ft_printf("Erreur : Carte invalide.\n");
		return (0);
	}
	return (1);
}

int	count_line(char **map)
{
	int	count;

	count = 0;
	while (map[count] != NULL)
		count++;
	return (count);
}

void	free_exit(char **map, void *mlx, t_assets *assets, void *window)
{
	free(map);
	mlx_destroy_window(mlx, window);
	free(mlx);
	free(assets);
}
