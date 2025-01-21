/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadahman <nadahman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 10:18:20 by nadahman          #+#    #+#             */
/*   Updated: 2025/01/21 13:15:20 by nadahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	test_algo(t_node **pile_a)
{
	t_node	*cur;

	if (*pile_a == NULL || (*pile_a)->next == NULL)
		return ;
	cur = *pile_a;
	if (cur->value > cur->next->value)
	{
		swap_a(pile_a);
		cur = *pile_a;
	}
	else
		cur = cur->next;
}

void	test_sort(t_node **pile_a, t_node **pile_b)
{
	t_node	*cur;
	int		pivot;
	t_node	*tmp;

	if (*pile_a == NULL || (*pile_a)->next == NULL)
		return ;
	cur = *pile_a;
	pivot = (*pile_a)->value;
	while (cur->next != NULL)
	{
		if (cur->next->value < pivot)
		{
			tmp = cur->next;
			cur->next = tmp->next;
			tmp->next = *pile_b;
			*pile_b = tmp;
		}
		else
			cur = cur->next;
	}
	while (*pile_b != NULL)
		push_a(pile_a, pile_b);
	if (*pile_a != NULL)
		test_sort(pile_a, pile_b);
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

void	cinq(t_node **pile_a, t_node **pile_b)
{
	int	min;
	int	pos;

	min = search_min(pile_a);
	pos = found_pos_nbr(pile_a, min);
	if (pos > 2)
	{
		reverse_rotate_a(pile_a);
		reverse_rotate_a(pile_a);
	}
	else
	{
		while (pos > 0)
		{
			rotate_a(pile_a);
			pos--;
		}
	}
	push_b(pile_a, pile_b);
	min = search_min(pile_a);
	pos = found_pos_nbr(pile_a, min);
	if (pos > 2)
		reverse_rotate_a(pile_a);
	else
	{
		while (pos > 0)
		{
			rotate_a(pile_a);
			pos--;
		}
	}
	push_b(pile_a, pile_b);
	trois(pile_a);
	push_a(pile_a, pile_b);
	push_a(pile_a, pile_b);
}
