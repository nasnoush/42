/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_moove.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadahman <nadahman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 14:09:54 by nadahman          #+#    #+#             */
/*   Updated: 2025/01/23 13:43:42 by nadahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_number(char *str)
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

// int	add_nodes(int argc, char **argv, t_node *head)
// {
// 	t_node	*tmp;
// 	int		i;

// 	tmp = head;
// 	i = 1;
// 	while (i < argc)
// 	{
// 		if (!is_number(argv[i]))
// 		{
// 			ft_printf("Error\n");
// 			return (0);
// 		}
// 		tmp->next = malloc(sizeof(t_node));
// 		if (tmp->next == NULL)
// 		{
// 			ft_printf("Error: Memory allocation failed\n");
// 			return (0);
// 		}
// 		tmp = tmp->next;
// 		tmp->value = atoi(argv[i]);
// 		tmp->next = NULL;
// 		i++;
// 	}
// 	return (1);
// }

// void	stock_pile(int argc, char **argv, t_node **head)
// {
// 	if (argc < 2 || !is_number(argv[1]))
// 	{
// 		ft_printf("Error\n");
// 		return ;
// 	}
// 	*head = malloc(sizeof(t_node));
// 	if (*head == NULL)
// 	{
// 		ft_printf("Error: Memory allocation failed\n");
// 		return ;
// 	}
// 	(*head)->value = atoi(argv[1]);
// 	(*head)->next = NULL;
// 	if (!add_nodes(argc, argv, *head))
// 		return ;
// }

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
