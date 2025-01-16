/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadahman <nadahman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 10:18:20 by nadahman          #+#    #+#             */
/*   Updated: 2025/01/16 11:29:19 by nadahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	test_algo(t_node **pile_a)
{
	t_node *cur;

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
	t_node *cur;
	int	pivot;
	t_node *tmp;

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
    {
        push_a(pile_a, pile_b);
    }
    if (*pile_a != NULL)
	{
        test_sort(pile_a, pile_b);
	}
}


void	trois(t_node **pile_a)
{
	int	a;
	int	b;
	int	c;

	a = (*pile_a)->value;
	b = (*pile_a)->next->value;
	c = (*pile_a)->next->next->value;
	
	if (a > b && b < c && a < c)
	{
		swap_a(pile_a);
	}
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
	{
		rotate_a(pile_a);
	}
	else if (a < b && b > c && a > c)
	{
		reverse_rotate_a(pile_a);
	}
}

void	cinq(t_node **pile_a, t_node **pile_b)
{
	push_b(pile_a, pile_b);
	push_b(pile_a, pile_b);
	trois(pile_a);
	if ((*pile_b)->value > (*pile_b)->next->value)
	{
		swap_b(*pile_b);
	}
	push_a(pile_a, pile_b);
	while ((*pile_a)->value > (*pile_a)->next->value)
	{
		rotate_a(pile_a);
	}
	push_a(pile_a, pile_b);
	while ((*pile_a)->value > (*pile_a)->next->value)
	{
		rotate_a(pile_a);
	}
}
	

// 	A	B
// 0/	2
// 	3
// 	4
// 	5
// 	1

// 1/	4	2
// 	5	3
// 	1
	
// 2/	1	2
// 	4	3
// 	5
	
// 3/	2	3
// 	1
// 	4
// 	5

// 4/	1	3
// 	4
// 	5
// 	2
	
// 5/	3
// 	1
// 	4
// 	5
// 	2
	
// 6/	1
// 	4
// 	5
// 	2
// 	3