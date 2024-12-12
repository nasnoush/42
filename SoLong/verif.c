/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadahman <nadahman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 13:39:17 by nadahman          #+#    #+#             */
/*   Updated: 2024/12/11 11:52:48 by nadahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GNL/get_next_line.h"
#include "printf/ft_printf.h"
#include "so_long.h"

int	verif_map(t_assets *assets)
{
	int	exit_count;
	int	item_count;
	int	start_count;

	if (!verif_assets(assets))
		return (0);
	exit_count = count_map_elements(assets, 'E');
	item_count = count_map_elements(assets, 'C');
	start_count = count_map_elements(assets, 'P');
	if (exit_count == 0 || item_count == 0 || start_count == 0)
	{
		ft_printf("Erreur : Il manque un element.\n");
		free_map(assets->map);
		assets->map = NULL;
		exit (0);
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
		free_map(assets->map);
		assets->map = NULL;
		return (0);
	}
	map_width = ft_strlen(assets->map[0]);
	i = 0;
	while (i < count_line(assets->map))
	{
		if ((int)ft_strlen(assets->map[i]) != map_width)
		{
			ft_printf("Erreur : Carte non rectangulaire\n");
			free_map(assets->map);
			assets->map = NULL;
			exit (0);
		}
		i++;
	}
	return (1);
}

int	verif_mur(t_assets *assets)
{
	int	i;
	int	j;

	verif_assets(assets);
	i = 0;
	while (i < count_line(assets->map))
	{
		j = 0;
		while (assets->map[i][j] != '\0')
		{
			if ((i == 0 || i == count_line(assets->map) - 1 || j == 0
					|| j == (int)ft_strlen(assets->map[i]) - 1)
				&& assets->map[i][j] != '1')
			{
				ft_printf("Erreur :\n");
				ft_printf("La carte n'est pas entourée de murs.\n");
				free_map(assets->map);
				assets->map = NULL;
				exit (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	check_duplicates(t_assets *assets)
{
	int	player_count;
	int	exit_count;

	if (!verif_assets(assets))
		return (0);
	player_count = count_map_elements(assets, 'P');
	exit_count = count_map_elements(assets, 'E');
	if (player_count != 1 || exit_count != 1)
	{
		ft_printf("Erreur :\n");
		ft_printf("Il doit y avoir exactement un personnage et une sortie.\n");
		free_map(assets->map);
		assets->map = NULL;
		exit (0);
	}
	return (1);
}

int	check_all_map_conditions(t_assets *assets)
{
	int	result;

	verif_assets(assets);
	result = 1;
	if (verif_map(assets) == 0)
		result = 0;
	else if (check_duplicates(assets) == 0)
		result = 0;
	else if (verif_rectangulaire(assets) == 0)
		result = 0;
	else if (verif_mur(assets) == 0)
		result = 0;
	else if (check_map_validity(assets) == 0)
	{
		printf("Erreur :\nAucun chemin valide\n");
		result = 0;
	}
	else if (result == 0 && assets->map)
	{
		free_map(assets->map);
		free(assets);
		assets->map = NULL;
		return (0);
	}
	return (result);
}
