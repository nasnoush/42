/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_moove.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadahman <nadahman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 14:09:54 by nadahman          #+#    #+#             */
/*   Updated: 2025/01/16 13:26:47 by nadahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stock_pile(int argc, char **argv, t_node **head)
{
	t_node *tmp;
	int i;

	*head = malloc(sizeof (t_node));
	if (*head == NULL)
		return ;
	(*head)->value = atoi(argv[1]);
	(*head)->next = NULL;
	tmp = *head;
	i = 2;
	while (i < argc)
	{
		tmp->next = malloc(sizeof(t_node));
		if (tmp->next == NULL)
			return ;
		tmp = tmp->next;
		tmp->value = atoi(argv[i]);
		tmp->next = NULL;
		i++;
	}
}

t_node	*push(t_node **head, int value)
{
	t_node	*new_node = NULL;

	new_node = malloc(sizeof(t_node));
	if (new_node == NULL)
		return (NULL);
	new_node->value = value;
	new_node->next = *head;
	*head = new_node;

	return (*head);
}

void	swap_a(t_node **pile_a)
{
	int tmp;

	if (pile_a == NULL || (*pile_a)->next == NULL)
		return ;
	tmp = (*pile_a)->value;
	(*pile_a)->value = (*pile_a)->next->value;
	(*pile_a)->next->value = tmp;
	
	ft_printf("sa\n");
}

void	swap_b(t_node *pile_b)
{
	int	tmp;

	if (pile_b == NULL || pile_b->next == NULL)
		return ;
	tmp = pile_b->value;
	pile_b->value = pile_b->next->value;
	pile_b->next->value = tmp;
	ft_printf("sb\n");
}

void	ss(t_node **pile_a, t_node **pile_b)
{
	int	tmp;
	int	tmp2;

	if ((*pile_a) == NULL || (*pile_a)->next == NULL || (*pile_b) ==  NULL || (*pile_b)->next == NULL)
		return ;

	tmp = (*pile_a)->value;
	(*pile_a)->value = (*pile_a)->next->value;
	(*pile_a)->next->value = tmp;

	tmp2 = (*pile_b)->value;
	(*pile_b)->value = (*pile_b)->next->value;
	(*pile_b)->next->value = tmp2;
	ft_printf("ss\n");
}


/*int main()
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

	swap_a(pile_a);

	printf("Pile A apres : ");
	print_pile(pile_a);
	printf("Pile B apres : ");
	print_pile(pile_b);

}*/

/*int main(int argc, char **argv)
{
	int	i;

	i = 0;
	t_node *pile_a = NULL;
	t_node *pile_b = NULL;

	push(&pile_a, atoi(argv[1]));
	push(&pile_b, atoi(argv[2]));
}*/











/*int main (int argc, char **argv)
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
}*/



