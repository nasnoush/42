/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nas <nas@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 09:09:55 by nas               #+#    #+#             */
/*   Updated: 2025/02/09 15:55:16 by nas              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_args(int	argc, char **argv)
{
	if (ft_atoi(argv[1]) < 1 || ft_atoi(argv[1]) > INT_MAX)
		return (0);
	if (ft_atoi(argv[2]) < 0 || ft_atoi(argv[3]) < 0 || ft_atoi(argv[4]) < 0)
		return (0);
        if (ft_atoi(argv[2]) > INT_MAX || ft_atoi(argv[3]) > INT_MAX || ft_atoi(argv[4])  > INT_MAX)
		return (0);
	if (argc == 6 && ft_atoi(argv[5]) < 0 && ft_atoi(argv[5]) > INT_MAX)
		return (0);
	return (1);
}

int check_arg_num(char **argv)
{
    int i;
    int j;

    i = 1;
    while (argv[i])
    {
        j = 0;
        while (argv[i][j])
        {
            if (argv[i][j] < '0' || argv[i][j] > '9')
            {
                printf("Error: Il faut que des chiffres (positifs) en arguments\n");
                return (0);
            }
            j++;
        }
        i++;
    }
    return (1);
}
