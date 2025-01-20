/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_moove2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nas <nas@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 10:25:54 by nas               #+#    #+#             */
/*   Updated: 2025/01/20 19:28:03 by nas              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_node **pile_a, t_node **pile_b)
{
	t_node *tmp;

	if (pile_b == NULL)
		return ;

	push(pile_a, (*pile_b)->value);

	tmp = *pile_b;
	
	(*pile_b) = (*pile_b)->next;
	free(tmp);
	ft_printf("pa\n");
	
}
void	push_b(t_node **pile_a, t_node **pile_b)
{
	t_node *tmp;

	if (pile_a == NULL)
		return ;
	
	push(pile_b, (*pile_a)->value);
	
	tmp = (*pile_a);
	*pile_a = (*pile_a)->next;
	free(tmp);
	ft_printf("pb\n");

}

void	rotate_a(t_node **pile_a)
{
	t_node *tmp;
	t_node *cur;

	if (*pile_a == NULL || (*pile_a)->next == NULL)
		return ;
	
	tmp = *pile_a;                                 
	cur = *pile_a;
	*pile_a = tmp->next;
	while (cur->next != NULL)
	{
		cur = cur->next;
	}
	cur->next = tmp;

	tmp->next = NULL;
	ft_printf("ra\n");
}

void	rotate_b(t_node **pile_b)
{
	t_node *tmp;
	t_node *cur;

	if (*pile_b == NULL || (*pile_b)->next == NULL)
		return ;

	tmp = *pile_b;
	cur = *pile_b;

	*pile_b = (*pile_b)->next;
	while (cur->next != NULL)
	{
		cur = cur->next;
	}
	cur->next = tmp;
	
	tmp->next = NULL;
	ft_printf("rb\n");
}
void	reverse_rotate_a(t_node **pile_a)
{
	t_node *cur;
	t_node *tmp;
	t_node *save;
	
	if (*pile_a == NULL || (*pile_a)->next == NULL)
		return ;
	save = *pile_a;
	cur = *pile_a;
	while (cur->next != NULL)
	{
		tmp = cur;
		cur = cur->next;
	}
	tmp->next = NULL;
	cur->next = save;
	*pile_a = cur;
	ft_printf("rra\n");
}
