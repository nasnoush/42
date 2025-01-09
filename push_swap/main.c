/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadahman <nadahman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 10:06:07 by nadahman          #+#    #+#             */
/*   Updated: 2025/01/09 10:22:14 by nadahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int main(int argc, char **argv)
{
    t_node	*valeur = NULL;
	
	valeur = malloc(sizeof(t_node));

	valeur->value = 2;
	
	printf("%d\n", valeur);
	return (0);
	
}