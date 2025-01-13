/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_moove2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadahman <nadahman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 10:25:54 by nas               #+#    #+#             */
/*   Updated: 2025/01/13 10:52:14 by nadahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_node **pile_a, t_node **pile_b)
{
	t_node *tmp;

	if (pile_b == NULL)
		return ;

	push(pile_a, (*pile_b)->value);

	tmp = *pile_b;
	
	(*pile_b) = (*pile_b)->next;
	free(tmp);
	
}
void	push_b(t_node **pile_a, t_node **pile_b)
{
	t_node *tmp;

	if (pile_a == NULL)
		return ;
	
	push(pile_b, (*pile_a)->value);
	
	tmp = (*pile_a);
	*pile_a = (*pile_a)->next;
	free(tmp);
}
int	count_node(t_node *pile)
{
	int i;

	i = 0;
	while (pile != NULL)
	{
		pile = pile->next;
		i++;
	}
	return (i);
}

void	rotate_a(t_node **pile_a)
{
	t_node *tmp;
	t_node *cur;

	if (*pile_a == NULL || (*pile_a)->next == NULL)
		return ;
	
	tmp = *pile_a;                                 
	cur = *pile_a;
	*pile_a = tmp->next;
	while (cur->next != NULL)
	{
		cur = cur->next;
	}
	cur->next = tmp;

	tmp->next = NULL;
	
}

void	rotate_b(t_node **pile_b)
{
	t_node *tmp;
	t_node *cur;

	if (*pile_b == NULL || (*pile_b)->next == NULL)
		return ;

	tmp = *pile_b;
	cur = *pile_b;

	*pile_b = (*pile_b)->next;
	while (cur->next != NULL)
	{
		cur = cur->next;
	}
	cur->next = tmp;
	
	tmp->next = NULL;
}
void	rr(t_node **pile_a, t_node **pile_b)
{
	rotate_a(pile_a);
	rotate_b(pile_b);
}
void	reverse_rotate_a(t_node **pile_a)
{
	t_node *cur;
	t_node *tmp;
	t_node *save;
	
	if (*pile_a == NULL || (*pile_a)->next == NULL)
		return ;
	
	save = *pile_a;
	cur = *pile_a;
	while (cur->next != NULL)
	{
		tmp = cur;
		cur = cur->next;
	}
	tmp->next = NULL;
	cur->next = save;
	*pile_a = cur;
}

void	reverse_rotate_b(t_node **pile_b)
{
	t_node *tmp;
	t_node *save;
	t_node *cur;

	if (*pile_b == NULL || (*pile_b)->next == NULL)
		return ;
	
	save = *pile_b;
	cur = *pile_b;
	while (cur->next != NULL)
	{
		tmp = cur;
		cur = cur->next;
	}
	tmp->next = NULL;
	cur->next = save;
	*pile_b = cur;
}

void rrr(t_node **pile_a, t_node **pile_b)
{
	reverse_rotate_a(pile_a);
	reverse_rotate_b(pile_b);
}


int main()
{
	t_node *pile_a = NULL;
	t_node *pile_b = NULL;


	push(&pile_a, 10);
	push(&pile_a, 20);
	push(&pile_a, 30);
	push(&pile_a, 40);
	
	push(&pile_b, 90);
	push(&pile_b, 70);
	push(&pile_b, 50);
	push(&pile_b, 60);
	
	printf("Pile A : ");
	print_pile(pile_a);
	printf("Pile B : ");
	print_pile(pile_b);

	rrr(&pile_a, &pile_b);

	printf("Pile A apres : ");
	print_pile(pile_a);
	printf("Pile B apres : ");
	print_pile(pile_b);

}