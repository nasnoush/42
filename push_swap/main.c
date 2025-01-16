/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadahman <nadahman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 10:06:07 by nadahman          #+#    #+#             */
/*   Updated: 2025/01/16 13:35:09 by nadahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_node *pile_a;
	t_node *pile_b = NULL;

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
	trois(&pile_a);
	ft_printf("Pile A : ");
	print_pile(pile_a);
	ft_printf("Pile B : ");
	print_pile(pile_b);

	return (0);
}

