/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadahman <nadahman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 11:30:57 by nas               #+#    #+#             */
/*   Updated: 2025/02/06 13:33:14 by nadahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void init_main(char **argv, t_philo *philo, t_philosophe **philosophe, pthread_t **threads)
{
    philo->nbr_philo = ft_atoi(argv[1]);
    philo->time_to_die = ft_atoi(argv[2]);
    philo->time_to_eat = ft_atoi(argv[3]);
    philo->time_to_sleep = ft_atoi(argv[4]);
	
    *philosophe = malloc(sizeof(t_philosophe) * philo->nbr_philo);
    if (*philosophe == NULL)
        exit(1);
	
    *threads = malloc(sizeof(pthread_t) * philo->nbr_philo);
    if (*threads == NULL)
        exit(1);
}

int main(int argc, char **argv)
{
	t_philo *philo;
	t_philosophe *philosophe;
	pthread_t *threads;

	if (argc != 5 && argc != 6)
	{
		printf("Error: Pas assez d'arguments\n");
		exit (1);
	}
	
	philo = malloc(sizeof(t_philo));
	if (philo == NULL)
		exit (1);
		
	init_main(argv, philo, &philosophe, &threads);
	if (argc == 6)
		philo->nbr_of_times_each_philo_must_eat = ft_atoi(argv[5]);
	else
		philo->nbr_of_times_each_philo_must_eat = -1;
		
	init_philo(&philosophe, philo);
	create_thread(philo, philosophe, threads);

	free (philo);
	free(philosophe);
	free(threads);
	return (0);
}
