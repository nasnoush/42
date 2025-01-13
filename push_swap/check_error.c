/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadahman <nadahman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 10:53:50 by nadahman          #+#    #+#             */
/*   Updated: 2025/01/13 14:05:06 by nadahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_error(char **argv)
{
	int	i;
	int j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (!argv[i][j] >= '0' && argv[i][j] <= '9')
			{
				ft_printf("Error\n");
				exit (1);
			}
			j++;
		}
		i++;
	}
}

void	check_double(char **argv)
{
	int i;
	int j;
	
	i = 1;

	while (argv[i])
	{
		j = i + 1;
		while(argv[j])
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
			{
				ft_printf("Error\n");
				exit (1);
			}
			j++;
		}
		i++;
	}
}
void	check_all(char **argv)
{
		check_error(argv);
		check_double(argv);
}


int	main(int argc, char **argv)
{
	if (argc < 3)
	{
		ft_printf("Error\n");
		return (0);
	}
	check_all(argv);
	return (0);
}


