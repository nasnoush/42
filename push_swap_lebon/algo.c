/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadahman <nadahman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 10:18:20 by nadahman          #+#    #+#             */
/*   Updated: 2025/01/27 11:25:32 by nadahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	little_sort(t_node **pile_a, t_node **pile_b, int nbr_element)
{
	if (nbr_element == 1)
		return ;
	else if (nbr_element == 2)
	{
		if ((*pile_a)->value > (*pile_a)->next->value)
			swap_a(pile_a);
		return ;
	}
	else if (nbr_element == 3)
	{
		trois(pile_a);
		return ;
	}
	else if (nbr_element == 4)
	{
		quatre(pile_a, pile_b);
		return ;
	}
	else if (nbr_element == 5)
	{
		cinq(pile_a, pile_b);
		return ;
	}
}

void	trie_chunks(t_node **pile_a, t_node **pile_b, t_chunks **chunks)
{
	int	nbr_element;
	int	min;
	int	max;
	int	chunk_size;

	nbr_element = count_int(pile_a);
	min = search_min(pile_a);
	max = search_max(pile_a);
	if (nbr_element <= 5)
	{
		little_sort(pile_a, pile_b, nbr_element);
		return ;
	}
	if (nbr_element <= 100)
		chunk_size = 5;
	else
		chunk_size = 11;
	create_chunks(chunks, min, max, chunk_size);
	trie_to_pile_b(pile_a, pile_b, chunks);
	trie_to_pile_a(pile_a, pile_b);
	verif_trie(pile_a);
}

void	trois(t_node **pile_a)
{
	int	a;
	int	b;
	int	c;

	if (!pile_a || !(*pile_a) || !(*pile_a)->next || !(*pile_a)->next->next)
		return ;
	a = (*pile_a)->value;
	b = (*pile_a)->next->value;
	c = (*pile_a)->next->next->value;
	if (a > b && b < c && a < c)
		swap_a(pile_a);
	else if (a < b && b > c && a < c)
	{
		swap_a(pile_a);
		rotate_a(pile_a);
	}
	else if (a > b && b > c)
	{
		swap_a(pile_a);
		reverse_rotate_a(pile_a);
	}
	else if (a > b && b < c && a > c)
		rotate_a(pile_a);
	else if (a < b && b > c && a > c)
		reverse_rotate_a(pile_a);
}

void	quatre(t_node **pile_a, t_node **pile_b)
{
	int	min;

	min = search_min(pile_a);
	calcul_nbr_moove_a(pile_a, min);
	push_b(pile_a, pile_b);
	trois(pile_a);
	push_a(pile_a, pile_b);
}

void	cinq(t_node **pile_a, t_node **pile_b)
{
	int	min;

	min = search_min(pile_a);
	calcul_nbr_moove_a(pile_a, min);
	push_b(pile_a, pile_b);
	min = search_min(pile_a);
	calcul_nbr_moove_a(pile_a, min);
	push_b(pile_a, pile_b);
	trois(pile_a);
	push_a(pile_a, pile_b);
	push_a(pile_a, pile_b);
}
