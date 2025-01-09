/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_moove.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadahman <nadahman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 14:09:54 by nadahman          #+#    #+#             */
/*   Updated: 2025/01/09 14:08:27 by nadahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


/*t_node	*sa(t_node *head, int value)
{
	t_node *pile_a;
	
	pile_a = malloc(sizeof(t_node));
	
	pile_a->value = value;
	pile_a->next = head;
	
	return (pile_a);
}*/




int main (int argc, char **argv)
{
	t_node *head;
	t_node *tmp;
	int nbr_val;
	int i;
	
	head = NULL;
	tmp = NULL;
	i = 2;
	head = malloc(sizeof(t_node));
	head->value = atoi(argv[1]);
	head->next = NULL;
	tmp = head;
	nbr_val = argc - 1;
	while (i < argc)
	{
		head->next = malloc(sizeof(t_node));
		head = head->next;
		head->value = atoi(argv[i]);
		head->next = NULL;
		i++;
	}
	i = 0;
	head = tmp;
	while (i < nbr_val)
	{
		printf("%i ", head->value);
		head = head->next;
		i++;
	}
	return (0);
}




7 2 9 6 3 12 41 20 32

pile a = 7 2 9
pile a = 2 7 9
pile a = 2 7 9 6 3 12
2 7 6 9 3 12
2 6 7 9 3 12
2 6 7 3 9 12
2637912
236