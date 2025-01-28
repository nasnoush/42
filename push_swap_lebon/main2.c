/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadahman <nadahman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 11:46:06 by nadahman          #+#    #+#             */
/*   Updated: 2025/01/27 13:35:36 by nadahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	handle_single_arg(char *arg, t_node **pile_a)
{
	char	**args;
	int		size;

	if (arg[0] == '\0')
	{
		ft_printf("Error\n");
		exit(1);
	}
	args = split_args(arg, &size);
	if (!args)
	{
		ft_printf("Error\n");
		exit(1);
	}
	check_all(args, args);
	stock_pile(size, args, pile_a, 1);
	transform_to_index(pile_a);
	free_split(args);
}

void	handle_multiple_args(int argc, char **argv, t_node **pile_a)
{
	check_all(argv + 1, NULL);
	stock_pile(argc - 1, argv + 1, pile_a, 0);
	transform_to_index(pile_a);
}

void	process_stack(t_node **pile_a, t_node **pile_b, t_chunks **chunks)
{
	if (if_is_sort(pile_a))
	{
		free_pile(pile_a);
		exit(1);
	}
	else
	{
		trie_chunks(pile_a, pile_b, chunks);
		last_verif(pile_a);
	}
}

void	free_all(t_node **pile_a, t_node **pile_b, t_chunks **chunks)
{
	if (pile_a && *pile_a)
		free_pile(pile_a);
	if (pile_b && *pile_b)
		free_pile(pile_b);
	if (chunks && *chunks)
		free_chunks(chunks);
}
