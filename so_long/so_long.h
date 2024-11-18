/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadahman <nadahman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 13:07:47 by nadahman          #+#    #+#             */
/*   Updated: 2024/11/18 13:29:00 by nadahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <unistd.h>
# include "minilibx/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include "GNL/get_next_line.h"

# define MAX_LINES 1000

typedef struct s_assets
{
	void	*sol1;
	void	*sol2;
	void	*mur;
	void	*contour;
	void	*collect;
	void	*perso;
	void	*exit;
	int		longueur;
	int		largeur;
	int		win_long;
	int		win_larg;
	char	**map;
	int		pos_y;
	int		pos_x;
	void	*mlx;
	void	*window;
	int		new_x;
	int		new_y;
}t_assets;

void		*def_assets_to_char(char i, t_assets *assets);
char		**charge_map(const char *filename);
void		place_assets(t_assets *assets, char **map, void *mlx, void *window);
t_assets	*load_assets(void *mlx);
void		aff_perso(t_assets *assets, void *mlx, void *window, char **map);
void		position_perso(t_assets *assets, char **map);
void		deplacement(t_assets *assets, int new_x, int new_y);
int			depl_haut(int keycode, t_assets *assets);
void		actualisation_map(t_assets *assets, void *mlx, void *window);
int			count_line(char **map);
int			keyboard(int keycode, t_assets *assets);

#endif