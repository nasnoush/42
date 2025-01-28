/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nas <nas@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 13:15:52 by nadahman          #+#    #+#             */
/*   Updated: 2025/01/28 08:42:51 by nas              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long int	ft_atoi(char *str)
{
	int			i;
	long int	r;
	int			s;

	i = 0;
	r = 0;
	s = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			s = s * -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		r = r * 10 + (str[i] - 48);
		i++;
	}
	return (r * s);
}

int	find_min_index(t_node **pile_a)
{
	t_node	*cur;
	int		min;
	int		index;
	int		min_index;

	if (!pile_a || !(*pile_a))
		return (-1);
	min = (*pile_a)->value;
	min_index = 0;
	cur = *pile_a;
	index = 0;
	while (cur != NULL)
	{
		if (cur->value < min)
		{
			min = cur->value;
			min_index = index;
		}
		cur = cur->next;
		index++;
	}
	return (min_index);
}
