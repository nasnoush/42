/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nas <nas@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 14:09:42 by nadahman          #+#    #+#             */
/*   Updated: 2025/01/13 18:37:13 by nas              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "printf/ft_printf.h"
#include <stdlib.h>
#include <stdio.h>


typedef struct  s_node{
    int             value;
    struct s_node   *next;
}t_node;

void        stock_pile(int argc, char **argv, t_node **head);
t_node      *push(t_node **head, int value);
void        swap_a(t_node *pile_a);
void        print_pile(t_node *head);
void        swap_b(t_node *pile_b);
void        ss(t_node **pile_a, t_node **pile_b);
int         count_node(t_node *pile_a);
long int    ft_atoi(char *str);
void	    check_all(char **argv);
void	    check_double(char **argv);
void	    check_error(char **argv);

#endif