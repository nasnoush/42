/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadahman <nadahman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 10:50:20 by nadahman          #+#    #+#             */
/*   Updated: 2025/01/27 11:25:38 by nadahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_pile(t_node **head)
{
	t_node	*tmp;

	while (*head != NULL)
	{
		tmp = *head;
		*head = (*head)->next;
		free(tmp);
	}
	*head = NULL;
}

void	print_chunks(t_chunks *chunks)
{
	int	i;

	i = 1;
	while (chunks)
	{
		ft_printf("Chunk %i: min = %d, max = %d\n", i, chunks->min,
			chunks->max);
		chunks = chunks->next;
		i++;
	}
}
