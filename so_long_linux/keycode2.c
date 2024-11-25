/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keycode2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadahman <nadahman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 13:43:40 by nadahman          #+#    #+#             */
/*   Updated: 2024/11/25 11:28:08 by nadahman         ###   ########.fr       */
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

int	keyboard(int keycode, t_assets *assets)
{
	if (keycode == KEY_W)
		depl_haut(keycode, assets);
	else if (keycode == KEY_S)
		depl_bas(keycode, assets);
	else if (keycode == KEY_A)
		depl_left(keycode, assets);
	else if (keycode == KEY_D)
		depl_right(keycode, assets);
	else if (keycode == KEY_ESC)
		close_window(keycode, assets);
	return (0);
}
