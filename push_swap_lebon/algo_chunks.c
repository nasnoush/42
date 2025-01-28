/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_chunks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadahman <nadahman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 12:47:13 by nas               #+#    #+#             */
/*   Updated: 2025/01/23 09:57:57 by nadahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_chunks(t_chunks **chunks, int cur_min, int cur_max)
{
	t_chunks	*new_chunks;
	t_chunks	*last;

	new_chunks = NULL;
	new_chunks = malloc(sizeof(t_chunks));
	if (new_chunks == NULL)
		return ;
	new_chunks->min = cur_min;
	new_chunks->max = cur_max;
	new_chunks->next = NULL;
	new_chunks->pre = NULL;
	if (*chunks == NULL)
		*chunks = new_chunks;
	else
	{
		last = *chunks;
		while (last->next)
		{
			last = last->next;
		}
		last->next = new_chunks;
		new_chunks->pre = last;
	}
}

void	create_chunks(t_chunks **chunks, int min, int max, int nb_chunks)
{
	int	chunks_size;
	int	i;
	int	cur_min;
	int	cur_max;
	int	reste;

	cur_min = min;
	i = 0;
	chunks_size = (max - min + 1) / nb_chunks;
	reste = (max - min + 1) % nb_chunks;
	while (i < nb_chunks)
	{
		if (i < reste)
			cur_max = cur_min + chunks_size;
		else
			cur_max = cur_min + chunks_size - 1;
		if (i == nb_chunks - 1)
		{
			cur_max = max;
		}
		add_chunks(chunks, cur_min, cur_max);
		cur_min = cur_max + 1;
		i++;
	}
}

void	calcul_nbr_moove_a(t_node **head, int value)
{
	int	pos;
	int	size;
	int	cout_ra;
	int	cout_rra;

	if (!head || !(*head))
		return ;
	size = count_int(head);
	pos = found_pos_nbr(head, value);
	if (pos == -1)
		return ;
	cout_ra = pos;
	cout_rra = size - pos;
	if (cout_ra <= cout_rra)
	{
		while (cout_ra-- > 0)
			rotate_a(head);
	}
	else
	{
		while (cout_rra-- > 0)
			reverse_rotate_a(head);
	}
}

void	calcul_nbr_moove_b(t_node **head, int value)
{
	int	pos;
	int	size;
	int	cout_rb;
	int	cout_rrb;

	if (!head || !(*head))
		return ;
	size = count_int(head);
	pos = found_pos_nbr(head, value);
	if (pos == -1)
		return ;
	cout_rb = pos;
	cout_rrb = size - pos;
	if (cout_rb <= cout_rrb)
	{
		while (cout_rb-- > 0)
			rotate_b(head);
	}
	else
	{
		while (cout_rrb-- > 0)
			reverse_rotate_b(head);
	}
}

void	trie_to_pile_b(t_node **pile_a, t_node **pile_b, t_chunks **chunks)
{
	t_node		*cur;
	t_chunks	*nb;

	nb = *chunks;
	while (nb != NULL)
	{
		cur = *pile_a;
		while (cur != NULL)
		{
			if (cur->value >= nb->min && cur->value <= nb->max)
			{
				calcul_nbr_moove_a(pile_a, cur->value);
				push_b(pile_a, pile_b);
				cur = *pile_a;
			}
			else
				cur = cur->next;
		}
		nb = nb->next;
	}
}
