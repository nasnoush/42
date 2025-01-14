/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadahman <nadahman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 10:18:20 by nadahman          #+#    #+#             */
/*   Updated: 2025/01/14 14:20:41 by nadahman         ###   ########.fr       */
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

