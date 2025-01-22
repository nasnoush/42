/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_moove3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nas <nas@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 19:30:52 by nas               #+#    #+#             */
/*   Updated: 2025/01/21 17:14:36 by nas              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_node(t_node *pile)
{
	int	i;

	i = 0;
	while (pile != NULL)
	{
		pile = pile->next;
		i++;
	}
	return (i);
}

void print_pile(t_node **head)
{
    t_node *current = *head;
    
    while (current != NULL)
    {
        ft_printf("%d ", current->value);
        current = current->next;
    }
    ft_printf("\n");
}

void	rrr(t_node **pile_a, t_node **pile_b)
{
	reverse_rotate_a(pile_a);
	reverse_rotate_b(pile_b);
	ft_printf("rrr\n");
}

void	rr(t_node **pile_a, t_node **pile_b)
{
	rotate_a(pile_a);
	rotate_b(pile_b);
	ft_printf("rr\n");
}
void	reverse_rotate_b(t_node **pile_b)
{
	t_node	*tmp;
	t_node	*save;
	t_node	*cur;

	if (*pile_b == NULL || (*pile_b)->next == NULL)
		return ;
	save = *pile_b;
	cur = *pile_b;
	while (cur->next != NULL)
	{
		tmp = cur;
		cur = cur->next;
	}
	tmp->next = NULL;
	cur->next = save;
	*pile_b = cur;
	ft_printf("rrb\n");
}
