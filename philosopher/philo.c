/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadahman <nadahman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 10:50:22 by nas               #+#    #+#             */
/*   Updated: 2025/02/05 13:27:10 by nadahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void init_philo(t_philosophe **philosophe, t_philo *philo)
{
	int i;

    i = 0;
	philo->forks = malloc(sizeof(pthread_mutex_t) * philo->nbr_philo);
    if (philo->forks == NULL)
        return;
    while (i < philo->nbr_philo)
    {
        (*philosophe)[i].id = i + 1;
        (*philosophe)[i].nb_meal = 0;
        (*philosophe)[i].etat = PENSER;
         (*philosophe)[i].forks_left = &philo->forks[i];  
        (*philosophe)[i].forks_right = &philo->forks[(i + 1) % philo->nbr_philo]; 
		pthread_mutex_init(&philo->forks[i], NULL);
        pthread_mutex_init(&philo->print_mutex, NULL);
        i++;
    }
}

void	create_thread(t_philo *philo, t_philosophe *philosophe, pthread_t *threads)
{
	int	i;
	
	i = 0;
	while (i < philo->nbr_philo)
	{
		philosophe[i].philo = philo;
		pthread_create(&threads[i], NULL, routine, &philosophe[i]);
		i++;
    }
	i = 0;
    while (i < philo->nbr_philo)
    {
        pthread_join(threads[i], NULL);
        i++;
    }
}