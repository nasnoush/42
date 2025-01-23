/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadahman <nadahman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 12:04:21 by nadahman          #+#    #+#             */
/*   Updated: 2025/01/22 12:01:01 by nadahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_word(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
			i++;
		if (str[i] && (str[i] != ' ' && str[i] != '\t' && str[i] != '\n'))
			count++;
		while (str[i] && (str[i] != ' ' && str[i] != '\t' && str[i] != '\n'))
			i++;
	}
	return (count);
}

static char	*allocate_word(char *str, int start, int end)
{
	int		i;
	char	*word;

	i = 0;
	word = malloc((end - start + 1) * sizeof(char));
	if (word == NULL)
		return (NULL);
	while (start < end)
	{
		word[i] = str[start];
		i++;
		start++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char *str)
{
	int		i;
	int		word_index;
	int		start;
	char	**tab_word;

	if (str == NULL)
		return (NULL);
	tab_word = malloc((count_word(str) + 1) * sizeof(char *));
	if (tab_word == NULL)
		return (NULL);
	i = 0;
	word_index = 0;
	while (str[i])
	{
		while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
			i++;
		start = i;
		while (str[i] && (str[i] != ' ' && str[i] != '\t' && str[i] != '\n'))
			i++;
		if (i > start)
			tab_word[word_index++] = allocate_word(str, start, i);
	}
	tab_word[word_index] = NULL;
	return (tab_word);
}

void	free_chunks(t_chunks **chunks)
{
	t_chunks	*current;
	t_chunks	*next;

	current = *chunks;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
	*chunks = NULL;
}

int	if_is_sort(t_node **pile_a)
{
	t_node	*cur;

	if (!pile_a || !*pile_a)
		return (1);
	cur = *pile_a;
	while (cur != NULL && cur->next != NULL)
	{
		if (cur->value > cur->next->value)
		{
			return (0);
		}
		cur = cur->next;
	}
	return (1);
}
