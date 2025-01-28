/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_moove.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadahman <nadahman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 14:09:54 by nadahman          #+#    #+#             */
/*   Updated: 2025/01/27 13:04:28 by nadahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	add_nodes(int argc, char **argv, t_node *head)
{
	t_node	*tmp;
	int		i;

	tmp = head;
	i = 1;
	while (i < argc)
	{
		if (!is_number(argv[i]))
		{
			free_pile(&head);
			ft_printf("Error\n");
			return (0);
		}
		tmp->next = malloc(sizeof(t_node));
		if (tmp->next == NULL)
			return (0);
		tmp = tmp->next;
		tmp->value = ft_atoi(argv[i]);
		tmp->next = NULL;
		i++;
	}
	return (1);
}

void	stock_pile(int argc, char **argv, t_node **head, int should_free)
{
	if (!is_number(argv[0]))
	{
		if (should_free && argv != NULL)
			free_split(argv);
		ft_printf("Error\n");
		exit(1);
	}
	*head = malloc(sizeof(t_node));
	if (*head == NULL)
	{
		if (should_free && argv != NULL)
			free_split(argv);
		ft_printf("Error\n");
		exit(1);
	}
	(*head)->value = ft_atoi(argv[0]);
	(*head)->next = NULL;
	if (argc > 1 && !add_nodes(argc, argv, *head))
	{
		free_pile(head);
		if (should_free && argv != NULL)
			free_split(argv);
		ft_printf("Error\n");
		exit(1);
	}
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
