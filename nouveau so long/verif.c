/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadahman <nadahman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 13:39:17 by nadahman          #+#    #+#             */
/*   Updated: 2024/12/02 14:37:05 by nadahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GNL/get_next_line.h"
#include "printf/ft_printf.h"
#include "so_long.h"

int	verif_map(t_assets *assets)
{
	int	i;
	int	j;
	int	exit_count;
	int	item_count;
	int	start_count;

	i = 0;
	exit_count = 0;
	item_count = 0;
	start_count = 0;
	if (!verif_assets(assets))
		return (0);
	while (i < count_line(assets->map))
	{
		j = 0;
		while (assets->map[i][j] != '\0')
		{
			if (assets->map[i][j] == 'E')
				exit_count++;
			else if (assets->map[i][j] == 'C')
				item_count++;
			else if (assets->map[i][j] == 'P')
				start_count++;
			j++;
		}
		i++;
	}
	if (exit_count != 1 || item_count == 0 || start_count != 1)
	{
		ft_printf("Erreur : Carte invalide\n");
		return (0);
	}
	return (1);
}

int	verif_rectangulaire(t_assets *assets)
{
	int	i;
	int	map_width;

	verif_assets(assets);
	if (count_line(assets->map) == 0)
	{
		ft_printf("Erreur : Carte vide\n");
		return (0);
	}
	map_width = ft_strlen(assets->map[0]);
	i = 0;
	while (i < count_line(assets->map))
	{
		if ((int)ft_strlen(assets->map[i]) != map_width)
		{
			ft_printf("Erreur : Carte non rectangulaire\n");
			return (0);
		}
		i++;
	}
	return (1);
}

int	verif_mur(t_assets *assets)
{
	int	i;
	int	j;

	i = 0;
	verif_assets(assets);
	while (i < count_line(assets->map))
	{
		j = 0;
		while (assets->map[i][j] != '\0')
		{
			if ((i == 0 || i == count_line(assets->map) - 1 || j == 0
					|| j == (int)ft_strlen(assets->map[i]) - 1)
				&& assets->map[i][j] != '1')
				return (ft_printf("La carte n'est pas entourée de murs.\n"), 0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_duplicates(t_assets *assets)
{
	int	i;
	int	j;
	int	player_count;
	int	exit_count;

	player_count = 0;
	exit_count = 0;
	i = 0;
	verif_assets(assets);
	while (assets->map[i])
	{
		j = 0;
		while (assets->map[i][j] != '\0')
		{
			if (assets->map[i][j] == 'P')
				player_count++;
			if (assets->map[i][j] == 'E')
				exit_count++;
			j++;
		}
		i++;
	}
	if (player_count != 1 || exit_count != 1)
	{
		ft_printf("Il doit y avoir exactement un personnage et une sortie.\n");
		return (0);
	}
	return (1);
}

void	change_end_line(char **map)
{
	int	i;
	int	len;	
	int	total_lines;

	total_lines = count_line(map);
	i = 0;
	while (map[i])
	{
		len = ft_strlen(map[i]);
		if (i != total_lines - 1 && map[i][len - 1] == '\n')
		{
			map[i][len - 1] = '\0';
		}
		i++;
	}
	len = ft_strlen(map[total_lines - 1]);
	if (map[total_lines - 1][len - 1] != '1')
	{
		map[total_lines - 1][len] = '1';
		map[total_lines - 1][len + 1] = '\0';
	}
}

int	check_all_map_conditions(t_assets *assets)
{
	if (!assets || !assets->map)
	{
		ft_printf("Erreur : Carte invalide.\n");
		return (0);
	}
	if (verif_map(assets) == 0)   // lui fonctionne
		return (0);
	if (check_duplicates(assets) == 0) // lui pas trop
		return (0);
	/*if (verif_rectangulaire(assets) == 0) // lui fonctionne pas
		return (0);
	if (verif_mur(assets) == 0)   // lui foncntionne pas
		return (0);*/
	return (1);
}

// ici il me manque la verif pour savoir si il existe un chemin valide
