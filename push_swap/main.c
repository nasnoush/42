/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadahman <nadahman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 10:06:07 by nadahman          #+#    #+#             */
/*   Updated: 2025/01/14 13:57:39 by nadahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_node *pile_a;
	if (argc == 1)
	{
		exit(1);
	}
	if (argc < 3)
	{
		ft_printf("Error\n");
		exit(1);
	}
	check_all(argv);
	stock_pile(argc, argv, &pile_a);
	test_algo(&pile_a);
	print_pile(pile_a);

	return (0);
}

