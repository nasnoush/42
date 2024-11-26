/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 13:07:47 by nadahman          #+#    #+#             */
/*   Updated: 2024/11/26 19:08:08 by marvin           ###   ########.fr       */
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
# include "printf.h"

# define MAX_LINES 1000

typedef struct s_assets
{
	void	*sol1;
	void	*sol2;
	void	*mur;
	void	*contour;
	void	*collect;
	int	 	collect1;
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
	int		collectible;
	int		count_moove;
	char	*screen;
	int		exit_count;
	int		item_count;
	int		start_count;

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
void		error(char *str);
void		free_map(char **map);
void		free_exit(char **map, void *mlx, t_assets *assets, void *window);
int			main(int argc, char **argv);
void		actualisation_deplacement(t_assets *assets, int new_x, int new_y);
int			depl_left(int keycode, t_assets *assets);
int			depl_right(int keycode, t_assets *assets);
int			depl_bas(int keycode, t_assets *assets);
int			close_window(int keycode, t_assets *assets);
void		aff_collect(t_assets *assets, void *mlx, void *window, char **map);
int			count_collect(char **map);
void		count_moove(t_assets *assets);
void		aff_moove(t_assets *assets, void *mlx, void *window);
void		aff_end_screen(void *mlx, void *window);
int			keyboard(int keycode, t_assets *assets);
void		*free_assets(t_assets *assets);
int 		close_window_x(int keycode, void *param);

#endif