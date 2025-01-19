/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nas <nas@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 10:06:07 by nadahman          #+#    #+#             */
/*   Updated: 2025/01/19 16:03:09 by nas              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_node *pile_a;
	t_node *pile_b = NULL;
	t_chunks	*chunks = NULL;

	if (argc == 1)
	{
		exit(1);
	}
	if (argc < 2)
	{
		ft_printf("Error\n");
		exit(1);
	}
	check_all(argv);
	stock_pile(argc, argv, &pile_a);
	trie_chunks(&pile_a, &pile_b, &chunks);
	verif_trie(&pile_a);
	last_verif(&pile_a);
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
// 	// count_int(&pile_a);
// 	// ft_printf("Il y'a %d éléments dans la pile A\n", count_int(&pile_a));
// 	// search_max(&pile_a);
// 	// search_min(&pile_a);
// 	// ft_printf("grand : %d petit : %d\n", search_max(&pile_a), search_min(&pile_a));
// 	// trie_to_pile_b(&pile_a, &pile_b, chunks);
// 	// trie_to_pile_a(&pile_a, &pile_b);
// 	// verif_trie(&pile_a);
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