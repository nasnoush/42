/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadahman <nadahman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 11:12:21 by nadahman          #+#    #+#             */
/*   Updated: 2025/01/27 10:54:19 by nadahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_int(t_node **pile_a)
{
	t_node	*cur;
	int		i;

	cur = *pile_a;
	i = 1;
	while (cur->next)
	{
		cur = cur->next;
		i++;
	}
	return (i);
}

int	search_max(t_node **pile_a)
{
	t_node	*cur;
	int		max;

	if (!pile_a || !(*pile_a))
		return (0);
	max = (*pile_a)->value;
	cur = *pile_a;
	while (cur != NULL)
	{
		if (cur->value > max)
			max = cur->value;
		cur = cur->next;
	}
	return (max);
}

int	search_min(t_node **pile_a)
{
	t_node	*cur;
	int		min;

	if (!pile_a || !(*pile_a))
		return (0);
	min = (*pile_a)->value;
	cur = *pile_a;
	while (cur != NULL)
	{
		if (cur->value < min)
			min = cur->value;
		cur = cur->next;
	}
	return (min);
}

int	is_number(char *str)
{
	int	i;

	if (!str || str[0] == '\0')
		return (0);
	i = 0;
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

int	is_only_spaces(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}
