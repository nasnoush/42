/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadahman <nadahman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 10:53:50 by nadahman          #+#    #+#             */
/*   Updated: 2025/01/21 11:43:35 by nadahman         ###   ########.fr       */
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

void    check_error(char **argv, char **args)
{
    int i;
    int j;

    i = 1;
    while (argv[i])
    {
        j = 0;
        if (argv[i][0] == '-')
        {
            if (!argv[i][1] || !(argv[i][1] >= '0' && argv[i][1] <= '9'))
            {
                if (args)
                    free_split(args);
                ft_printf("Error\n");
                exit(1);
            }
            j = 1;
        }
        while (argv[i][j])
        {
            if (!(argv[i][j] >= '0' && argv[i][j] <= '9'))
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

void check_double(char **argv, char **args)
{
    int i;
    int j;

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
