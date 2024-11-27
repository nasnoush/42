/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadahman <nadahman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 13:39:17 by nadahman          #+#    #+#             */
/*   Updated: 2024/11/27 13:49:02 by nadahman         ###   ########.fr       */
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
	j = 0;
	exit_count = 0;
	item_count = 0;
	start_count = 0;
	if (!assets || !assets->map)
	{
		ft_printf("Erreur : Carte invalide.\n");
		return (0);
	}
	while (i < count_line(assets->map))
	{
		j = 0;
		while (assets->map[i][j] != '\0')
		{
			if (assets->map[i][j] == 'E')
				exit_count++;
			if (assets->map[i][j] == 'C')
				item_count++;
			if (assets->map[i][j] == 'P')
				start_count++;
			j++;
		}
		i++;
	}
	if (exit_count == 0 || item_count == 0 || start_count == 0)
		return (0);
	return (1);
}

int	verif_rectangulaire(t_assets *assets)
{
	int	i;
	int	map_width;

	i = 0;
	map_width = ft_strlen(assets->map[0]);
	if (!assets || !assets->map)
	{
		ft_printf("Erreur : Carte invalide.\n");
		return (0);
	}
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
	if (!assets || !assets->map)
	{
		ft_printf("Erreur : Carte invalide.\n");
		return (0);
	}
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

int	check_duplicates(char **map)
{
	int	i;
	int	j;
	int	player_count;
	int	exit_count;

	player_count = 0;
	exit_count = 0;
	i = 0;
	if (!map)
		return (0);
	while (map[i])
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == 'P')
				player_count++;
			if (map[i][j] == 'E')
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

	i = 0;
	while (map[i])
	{
		len = ft_strlen(map[i]);
		if (map[i][len -1] == '\n')
			map[i][len - 1] = '\0';
		i++;
	}
}

int	check_all_map_conditions(t_assets *assets)
{
	if (!assets || !assets->map)
	{
		ft_printf("Erreur : Carte invalide.\n");
		return (0);
	}
	change_end_line(assets->map);
	if (verif_map(assets) == 0)
		return (0);
	if (verif_rectangulaire(assets) == 0)
		return (0);
	if (verif_mur(assets) == 0)
		return (0);
	if (check_duplicates(assets->map) == 0)
		return (0);
	return (1);
}

// ici il me manque la verif pour savoir si il existe un chemin valide