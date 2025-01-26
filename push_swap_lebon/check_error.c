/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nas <nas@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 10:53:50 by nadahman          #+#    #+#             */
/*   Updated: 2025/01/26 14:08:48 by nas              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_pile(t_node **head)
{
	t_node	*tmp;

	while (*head != NULL)
	{
		tmp = *head;
		*head = (*head)->next;
		free(tmp);
	}
	*head = NULL;
}
void handle_error(char **args, t_node **pile_a)
{
    if (args)
        free_split(args); // Libère le tableau d'arguments
    if (pile_a && *pile_a)
        free_pile(pile_a); // Libère la pile
    ft_printf("Error\n"); // Affiche le message d'erreur
}

int	check_argument(char *arg)
{
	int	j;

	j = 0;
	if (arg[0] == '-')
	{
		if (!arg[1] || !(arg[1] >= '0' && arg[1] <= '9'))
		{
			return (0);
		}
		j = 1;
	}
	while (arg[j])
	{
		if (!(arg[j] >= '0' && arg[j] <= '9'))
		{
			return (0);
		}
		j++;
	}
	return (1);
}

void	check_error(char **argv, char **args)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (!check_argument(argv[i]))
		{
			if (args)
				free_split(args);
			ft_printf("Error\n");
			exit(1);
		}
		i++;
	}
}

void	check_double(char **argv, char **args)
{
	int	i;
	int	j;

	i = 0;
	while (argv[i])
	{
		j = i + 1;
		while (argv[j])
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
			{
				if (args)
					free_split(args);
				ft_printf("Error\n");
				exit(1);
			}
			j++;
		}
		i++;
	}
}

void	check_all(char **argv, char **args)
{
	check_error(argv, args);
	check_double(argv, args);
}
