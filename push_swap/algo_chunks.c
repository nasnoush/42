/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_chunks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nas <nas@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 12:47:13 by nas               #+#    #+#             */
/*   Updated: 2025/01/20 19:24:55 by nas              ###   ########.fr       */
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
	int reste;

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

void	calcul_nbr_moove(t_node **head, int value)
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
		while (cout_ra > 0)
		{
			rotate_a(head);
			cout_ra--;
		}
	}
	else
	{
		while (cout_rra > 0)
		{
			reverse_rotate_a(head);
			cout_rra--;
		}
	}
}


void	trie_to_pile_b(t_node **pile_a, t_node **pile_b, t_chunks **chunks)
{
	t_node *cur;
	t_chunks *nb;

	nb = *chunks;
	while (nb != NULL)
	{
		cur = *pile_a;
		while (cur != NULL)
		{
			if (cur->value >= nb->min && cur->value <= nb->max)
			{
				calcul_nbr_moove(pile_a, cur->value);
				push_b(pile_a, pile_b);
				cur = *pile_a;
			}
			else
				cur = cur->next;
		}
		nb = nb->next;
	}
}


void	trie_chunks(t_node **pile_a, t_node **pile_b, t_chunks **chunks)
{
	int	nbr_element;
	int	min;
	int max;
	
	nbr_element = count_int(pile_a);
	min = search_min(pile_a);
	max = search_max(pile_a);
	if (nbr_element == 1)
	{
		return ;
	}
	else if (nbr_element == 2)
	{
		if ((*pile_a)->value > (*pile_a)->next->value)
			swap_a(pile_a);
	}
	else if (nbr_element == 3)
		trois(pile_a);
	else if (nbr_element == 5)
		cinq(pile_a, pile_b);
	else if (nbr_element <= 100 && nbr_element > 5)
	{
		create_chunks(chunks, min, max, 5);
		// print_chunks(*chunks);
		trie_to_pile_b(pile_a, pile_b, chunks);
		trie_to_pile_a(pile_a, pile_b);
		verif_trie(pile_a);
	}
	else
	{	
		create_chunks(chunks, min, max, 11);
		// print_chunks(*chunks);
		trie_to_pile_b(pile_a, pile_b, chunks);
		trie_to_pile_a(pile_a, pile_b);
		verif_trie(pile_a);
	}
}

