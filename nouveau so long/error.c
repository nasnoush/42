/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 10:16:19 by nadahman          #+#    #+#             */
/*   Updated: 2024/11/30 12:18:34 by marvin           ###   ########.fr       */
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

void	verif_assets(t_assets *assets)
{
	if (!assets || !assets->map)
	{
		ft_printf("Erreur : Carte invalide.\n");
		return (0);
	}
}