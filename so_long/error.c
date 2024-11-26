/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadahman <nadahman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 10:16:19 by nadahman          #+#    #+#             */
/*   Updated: 2024/11/26 13:59:28 by nadahman         ###   ########.fr       */
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

void	*free_assets(t_assets *assets)
{
	if (!assets)
		return (NULL);
	if (assets->mlx)
	{
		mlx_destroy_image(assets->mlx, assets->sol1);
		mlx_destroy_image(assets->mlx, assets->exit);
		mlx_destroy_image(assets->mlx, assets->contour);
		mlx_destroy_image(assets->mlx, assets->perso);
		mlx_destroy_image(assets->mlx, assets->collect);
	}
	free(assets);
	return (NULL);
}
