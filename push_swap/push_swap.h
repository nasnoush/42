/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadahman <nadahman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 14:09:42 by nadahman          #+#    #+#             */
/*   Updated: 2025/01/22 11:46:41 by nadahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "printf/ft_printf.h"
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_node
{
	int				value;
	struct s_node	*next;
}					t_node;

typedef struct s_chunks
{
	int				max;
	int				min;
	struct s_chunks	*pre;
	struct s_chunks	*next;
}					t_chunks;

char	**split_args(char *str, int *size);
void				handle_single_arg(char *arg, t_node **pile_a);
void				handle_multiple_args(int argc, char **argv, t_node **pile_a);
void				process_stack(t_node **pile_a, t_node **pile_b, t_chunks **chunks);
void				free_all(t_node **pile_a, t_node **pile_b, t_chunks **chunks);
void				transform_to_index(t_node **head);
void				stock_pile(int argc, char **argv, t_node **head);
t_node				*push(t_node **head, int value);
void				swap_a(t_node **pile_a);
void				print_pile(t_node **head);
void				swap_b(t_node *pile_b);
void				ss(t_node **pile_a, t_node **pile_b);
int					count_node(t_node *pile_a);
long int			ft_atoi(char *str);
void	            check_all(char **argv, char **args);
void                check_double(char **argv, char **args);
void				check_error(char **argv, char **args);
void				test_algo(t_node **pile_a);
void				rrr(t_node **pile_a, t_node **pile_b);
void				rr(t_node **pile_a, t_node **pile_b);
void				reverse_rotate_b(t_node **pile_b);
void				push_a(t_node **pile_a, t_node **pile_b);
void				push_b(t_node **pile_a, t_node **pile_b);
void				rotate_a(t_node **pile_a);
void				rotate_b(t_node **pile_b);
void				reverse_rotate_a(t_node **pile_a);
void				test_sort(t_node **pile_a, t_node **pile_b);
void				trois(t_node **pile_a);
void				cinq(t_node **pile_a, t_node **pile_b);
int					count_moove(char *str);
int					count_int(t_node **pile_a);
int					search_max(t_node **pile_a);
int					search_min(t_node **pile_a);
void				create_chunks(t_chunks **chunks, int min, int max,
						int nb_chunks);
void				trie_chunks(t_node **pile_a, t_node **pile_b,
						t_chunks **chunks);
void				add_chunks(t_chunks **chunks, int cur_min, int cur_max);
void				print_chunks(t_chunks *chunks);
void				trie_to_pile_b(t_node **pile_a, t_node **pile_b,
						t_chunks **chunks);
void				trie_to_pile_a(t_node **pile_a, t_node **pile_b);
void				verif_trie(t_node **pile_a);
void				free_pile(t_node **head);
void				last_verif(t_node **pile_a);
void				verif_trie(t_node **pile_a);
int					verif_pile_trie(t_node **pile_a);
int					found_pos_nbr(t_node **head, int value);
void    calcul_nbr_moove_a(t_node **head, int value);
void    calcul_nbr_moove_b(t_node **head, int value);
void				free_chunks(t_chunks **chunks);
char				**ft_split(char *str);
int					count_word(char *str);
int					if_is_sort(t_node **pile_a);
void	free_split(char **split);

#endif