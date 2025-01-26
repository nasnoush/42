/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_chunks2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nas <nas@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 13:34:47 by nas               #+#    #+#             */
/*   Updated: 2025/01/21 18:14:01 by nas              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	trie_to_pile_a(t_node **pile_a, t_node **pile_b)
{
	int	max;

	while (*pile_b != NULL)
	{
		max = search_max(pile_b);
		calcul_nbr_moove_b(pile_b, max);
		push_a(pile_a, pile_b);
	}
}

int	verif_pile_trie(t_node **pile_a)
{
	t_node	*cur;

	cur = *pile_a;
	while (cur != NULL && cur->next != NULL)
	{
		if (cur->value > cur->next->value)
			return (0);
		cur = cur->next;
	}
	return (1);
}

void	verif_trie(t_node **pile_a)
{
	int	min;

	if (verif_pile_trie(pile_a) == 1)
		return ;
	min = search_min(pile_a);
	calcul_nbr_moove_a(pile_a, min);
}

void	last_verif(t_node **pile_a)
{
	int	min;

	if (verif_pile_trie(pile_a) == 1)
		return ;
	min = search_min(pile_a);
	calcul_nbr_moove_a(pile_a, min);
}

int	found_pos_nbr(t_node **head, int value)
{
	t_node	*cur;
	int		pos;

	pos = 0;
	cur = *head;
	while (cur != NULL)
	{
		if (cur->value == value)
		{
			return (pos);
		}
		pos++;
		cur = cur->next;
	}
	return (-1);
}
