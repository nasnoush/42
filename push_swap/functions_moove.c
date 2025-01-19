/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_moove.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nas <nas@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 14:09:54 by nadahman          #+#    #+#             */
/*   Updated: 2025/01/19 13:31:05 by nas              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stock_pile(int argc, char **argv, t_node **head)
{
	t_node *tmp;
	int i;

	*head = malloc(sizeof (t_node));
	if (*head == NULL)
		return ;
	(*head)->value = atoi(argv[1]);
	(*head)->next = NULL;
	tmp = *head;
	i = 2;
	while (i < argc)
	{
		tmp->next = malloc(sizeof(t_node));
		if (tmp->next == NULL)
			return ;
		tmp = tmp->next;
		tmp->value = atoi(argv[i]);
		tmp->next = NULL;
		i++;
	}
}

t_node	*push(t_node **head, int value)
{
	t_node	*new_node = NULL;

	new_node = malloc(sizeof(t_node));
	if (new_node == NULL)
		return (NULL);
	new_node->value = value;
	new_node->next = *head;
	*head = new_node;

	return (*head);
}

void	swap_a(t_node **pile_a)
{
	int tmp;

	if (pile_a == NULL || (*pile_a)->next == NULL)
		return ;
	tmp = (*pile_a)->value;
	(*pile_a)->value = (*pile_a)->next->value;
	(*pile_a)->next->value = tmp;
	
	ft_printf("sa\n");
}

void	swap_b(t_node *pile_b)
{
	int	tmp;

	if (pile_b == NULL || pile_b->next == NULL)
		return ;
	tmp = pile_b->value;
	pile_b->value = pile_b->next->value;
	pile_b->next->value = tmp;
	ft_printf("sb\n");
}

void	ss(t_node **pile_a, t_node **pile_b)
{
	int	tmp;
	int	tmp2;

	if ((*pile_a) == NULL || (*pile_a)->next == NULL || (*pile_b) ==  NULL || (*pile_b)->next == NULL)
		return ;

	tmp = (*pile_a)->value;
	(*pile_a)->value = (*pile_a)->next->value;
	(*pile_a)->next->value = tmp;

	tmp2 = (*pile_b)->value;
	(*pile_b)->value = (*pile_b)->next->value;
	(*pile_b)->next->value = tmp2;
	ft_printf("ss\n");
}
