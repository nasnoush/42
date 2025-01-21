/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadahman <nadahman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 10:06:07 by nadahman          #+#    #+#             */
/*   Updated: 2025/01/21 14:19:08 by nadahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	**split_args(char *str, int *size)
{
	char	**args;

	args = ft_split(str);
	if (!args)
		return (NULL);
	*size = count_word(str);
	return (args);
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
int	main(int argc, char **argv)
{
	t_node		*pile_a;
	t_node		*pile_b;
	t_chunks	*chunks;
	char		**args;
	int			size;

	pile_b = NULL;
	chunks = NULL;
	args = NULL;
    if (argv[1][0] == '\0')
    {
        free_pile(&pile_a);
        exit(1);
    }
	if (argc == 1)
		exit(1);
	if (argc == 2)
	{
		args = split_args(argv[1], &size);
		if (!args)
		{
			ft_printf("Error\n");
			exit(1);
		}
		check_all(args, args);
		stock_pile(size, args, &pile_a);
		free_split(args);
	}
	else
	{
		check_all(argv + 1, NULL);
		stock_pile(argc - 1, argv + 1, &pile_a);
	}
	if (if_is_sort(&pile_a))
    {
        free_pile(&pile_a);
		exit(1);
    }
	else
	{
		trie_chunks(&pile_a, &pile_b, &chunks);
		// verif_trie(&pile_a);
		// last_verif(&pile_a);
	}
	// ft_printf("Pile A : ");
	// print_pile(pile_a);
	// ft_printf("Pile B : ");
	// print_pile(pile_b);
	free_pile(&pile_a);
	free_chunks(&chunks);
	free_pile(&pile_b);
	return (0);
}

// int	main(int argc, char **argv)
// {
// 	t_node *pile_a;
// 	t_node *pile_b = NULL;
// 	t_chunks	*chunks = NULL;

// 	if (argc == 1)
// 	{
// 		exit(1);
// 	}
// 	if (argc < 2)
// 	{
// 		ft_printf("Error\n");
// 		exit(1);
// 	}
// 	check_all(argv);
// 	stock_pile(argc, argv, &pile_a);
// 	count_int(&pile_a);
// 	ft_printf("Il y'a %d éléments dans la pile A\n", count_int(&pile_a));
// 	search_max(&pile_a);
// 	search_min(&pile_a);
// 	ft_printf("grand : %d petit : %d\n", search_max(&pile_a),
//		search_min(&pile_a));
// 	trie_to_pile_b(&pile_a, &pile_b, &chunks);
// 	trie_to_pile_a(&pile_a, &pile_b);
// 	verif_trie(&pile_a);
// 	trie_chunks(&pile_a, &pile_b, &chunks);
// 	verif_trie(&pile_a);
// 	last_verif(&pile_a);
// 	// free_pile(&pile_a);
// 	// free_pile(&pile_b);
// 	ft_printf("Pile A : ");
// 	print_pile(pile_a);
// 	ft_printf("Pile B : ");
// 	print_pile(pile_b);

// 	return (0);
// }
