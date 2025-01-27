/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadahman <nadahman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 10:06:07 by nadahman          #+#    #+#             */
/*   Updated: 2025/01/27 13:04:50 by nadahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**split_args(char *str, int *size)
{
	char	**args;

	args = ft_split(str);
	if (!args)
		return (NULL);
	*size = count_word(str);
	return (args);
}

int	main(int argc, char **argv)
{
	t_node		*pile_a;
	t_node		*pile_b;
	t_chunks	*chunks;

	pile_a = NULL;
	pile_b = NULL;
	chunks = NULL;
	if (argc == 1)
		exit(1);
	if (argc == 2)
		handle_single_arg(argv[1], &pile_a);
	else
		handle_multiple_args(argc, argv, &pile_a);
	process_stack(&pile_a, &pile_b, &chunks);
	free_all(&pile_a, &pile_b, &chunks);
	return (0);
}

void	free_split(char **split)
{
	int	i;

	if (!split)
		return ;
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}
