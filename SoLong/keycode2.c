/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keycode2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadahman <nadahman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 13:43:40 by nadahman          #+#    #+#             */
/*   Updated: 2024/12/05 13:59:06 by nadahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "GNL/get_next_line.h"
#include "printf/ft_printf.h"

int	close_window_x(t_assets *assets)
{
	mlx_destroy_window(assets->mlx, assets->window);
	free_map(assets->map);
	free(assets);
	exit(0);
	return (0);
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

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
		{
			return ((char *)&s[i]);
		}
		i++;
	}
	if ((char)c == '\0')
	{
		return ((char *)&s[i]);
	}
	return (NULL);
}
