/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nas <nas@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 10:53:50 by nadahman          #+#    #+#             */
/*   Updated: 2025/01/28 09:13:15 by nas              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	handle_error(char **args, t_node **pile_a)
{
	if (args)
		free_split(args);
	if (pile_a && *pile_a)
		free_pile(pile_a);
	ft_printf("Error\n");
}

int check_argument(char *arg)
{
    int         j;
    long int    val;

    j = 0;
    if (!arg || !*arg)
        return (0);
    if (arg[0] == '-' || arg[0] == '+')
    {
        if (!arg[1])
            return (0);
        j = 1;
    }
    while (arg[j])
    {
        if (!(arg[j] >= '0' && arg[j] <= '9'))
            return (0);
        j++;
    }
    val = ft_atoi(arg);
    if (val > INT_MAX || val < INT_MIN)
        return (0);
    return (1);
}

void check_error(char **argv, char **args)
{
    int i;

    if (!argv)
        return ;
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

void check_and_validate_args(char **args, int size)
{
    int i;

    if (!args || size == 0)
    {
        ft_printf("Error\n");
        exit(1);
    }
    i = 0;
    while (args[i])
    {
        if (!check_argument(args[i]))
        {
            free_split(args);
            ft_printf("Error\n");
            exit(1);
        }
        i++;
    }
    check_all(args, args);
}

void	check_all(char **argv, char **args)
{
	check_error(argv, args);
	check_double(argv, args);
}
