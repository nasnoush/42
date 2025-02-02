/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nas <nas@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 11:30:57 by nas               #+#    #+#             */
/*   Updated: 2025/02/02 10:28:12 by nas              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int argc, char **argv)
{
	t_philo *philo;

	if (argc != 5 && argc != 6)
	{
		printf("Error: Pas assez d'arguments\n");
		exit (1);
	}
	philo = malloc(sizeof(t_philo));
	if (philo == NULL)
		return (NULL);
	philo->nbr_philo = ft_atoi(argv[1]);
	philo->time_to_die = ft_atoi(argv[2]);
	philo->time_to_eat = ft_atoi(argv[3]);
	philo->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		philo->nbr_of_times_each_philo_must_eat = ft_atoi(argv[5]);
	else
		philo->nbr_of_times_each_philo_must_eat = -1;
	// mettre les autres elements

	// ajouter la creation des threads
	free (philo);
	return (0);
}
