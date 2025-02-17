/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nas <nas@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 10:06:07 by nadahman          #+#    #+#             */
/*   Updated: 2025/01/25 13:59:35 by nas              ###   ########.fr       */
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

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}
// int	main(int argc, char **argv)
// {
// 	t_node		*pile_a;
// 	t_node		*pile_b;
// 	t_chunks	*chunks;
// 	char		**args;
// 	int			size;

// 	pile_a = NULL;
// 	pile_b = NULL;
// 	chunks = NULL;
// 	args = NULL;
// 	if (argc == 1)
// 		exit(1);
// 	if (argc == 2)
// 	{
// 		if (argv[1][0] == '\0')
// 		{
// 			exit(1);
// 		}
// 		args = split_args(argv[1], &size);
// 		if (!args)
// 		{
// 			ft_printf("Error\n");
// 			exit(1);
// 		}
// 		check_all(args, args);
// 		stock_pile(size, args, &pile_a);
// 		free_split(args);
// 	}
// 	else
// 	{
// 		check_all(argv + 1, NULL);
// 		stock_pile(argc - 1, argv + 1, &pile_a);
// 		transform_to_index(&pile_a);
// 	}
// 	if (if_is_sort(&pile_a))
// 	{
// 		free_pile(&pile_a);
// 		exit(1);
// 	}
// 	else
// 	{
// 		trie_chunks(&pile_a, &pile_b, &chunks);
// 		last_verif(&pile_a);
// 	}
// 	free_pile(&pile_a);
// 	free_chunks(&chunks);
// 	free_pile(&pile_b);
// 	return (0);
// }