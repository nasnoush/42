/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nas <nas@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 11:12:21 by nadahman          #+#    #+#             */
/*   Updated: 2025/01/26 14:34:48 by nas              ###   ########.fr       */
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

int is_only_spaces(char *str)
{
    int i = 0;

    while (str[i])
    {
        if (str[i] != ' ') // Si un caractère non-espace est trouvé
            return (0);
        i++;
    }
    return (1); // Retourne 1 si la chaîne est uniquement composée d'espaces
}

