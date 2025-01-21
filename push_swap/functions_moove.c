/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_moove.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadahman <nadahman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 14:09:54 by nadahman          #+#    #+#             */
/*   Updated: 2025/01/21 11:11:11 by nadahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_number(char *str)
{
	int	i;

	i = 0;
	if (!str || str[0] == '\0')
		exit(1);
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

void	stock_pile(int argc, char **argv, t_node **head)
{
	t_node	*tmp;
	int		i;

	*head = malloc(sizeof(t_node));
	if (*head == NULL)
		return ;
	if (!is_number(argv[0]))
	{
		ft_printf("Error\n", argv[1]);
		return ;
	}
	(*head)->value = atoi(argv[0]);
	(*head)->next = NULL;
	tmp = *head;
	i = 1;
	while (i < argc)
	{
		if (!is_number(argv[1]))
		{
			ft_printf("Error\n", argv[1]);
			return ;
		}
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
	t_node	*new_node;

	new_node = NULL;
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
	int	tmp;

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

	if ((*pile_a) == NULL || (*pile_a)->next == NULL || (*pile_b) == NULL
		|| (*pile_b)->next == NULL)
		return ;
	tmp = (*pile_a)->value;
	(*pile_a)->value = (*pile_a)->next->value;
	(*pile_a)->next->value = tmp;
	tmp2 = (*pile_b)->value;
	(*pile_b)->value = (*pile_b)->next->value;
	(*pile_b)->next->value = tmp2;
	ft_printf("ss\n");
}
