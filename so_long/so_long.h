/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadahman <nadahman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 13:07:47 by nadahman          #+#    #+#             */
/*   Updated: 2024/11/12 14:12:21 by nadahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <unistd.h>
# include "mlx/mlx.h"
# include <stdio.h>
# include <stdlib.h>

# define MAX_LINES 1000

typedef struct s_assets
{
	void	*sol1;
	void	*sol2;
	void	*mur;
	void	*collect;
	void	*perso;
	void	*exit;
	void	*sol1_image;
	void	*sol2_image;
	void	*mur_image;
	void	*collect_image;
	void	*perso_image;
	void	*exit_image;
}t_assets;

void	*def_assets_to_char(char i, t_assets *assets);

#endif