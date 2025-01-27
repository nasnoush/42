/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nas <nas@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 10:53:49 by nadahman          #+#    #+#             */
/*   Updated: 2025/01/25 13:41:28 by nas              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

static void	sort_array(int *arr, int size)
{
	int	i;
	int	j;
	int	min_idx;

	i = 0;
	while (i < size - 1)
	{
		min_idx = i;
		j = i + 1;
		while (j < size)
		{
			if (arr[j] < arr[min_idx])
				min_idx = j;
			j++;
		}
		if (min_idx != i)
			swap(&arr[min_idx], &arr[i]);
		i++;
	}
}

static int	get_index(int *sorted_arr, int size, int value)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (sorted_arr[i] == value)
			return (i);
		i++;
	}
	return (-1);
}

void	transform_to_index(t_node **head)
{
	t_node	*current;
	int		*values;
	int		size;
	int		i;

	size = count_int(head);
	values = (int *)malloc(sizeof(int) * size);
	if (!values)
		return ;
	current = *head;
	i = 0;
	while (current != NULL)
	{
		values[i] = current->value;
		current = current->next;
		i++;
	}
	sort_array(values, size);
	current = *head;
	while (current != NULL)
	{
		current->value = get_index(values, size, current->value);
		current = current->next;
	}
	free(values);
}
