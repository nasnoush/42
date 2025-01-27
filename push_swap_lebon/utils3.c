/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadahman <nadahman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 13:15:52 by nadahman          #+#    #+#             */
/*   Updated: 2025/01/27 14:02:25 by nadahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_int(long int r, int sign)
{
	if ((sign == 1 && r > INT_MAX) || (sign == -1 && r * sign < INT_MIN))
	{
		ft_printf("Error\n");
		exit(1);
	}
}

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
		check_int(r, s);
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
