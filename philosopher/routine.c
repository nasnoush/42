/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadahman <nadahman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 12:38:34 by nadahman          #+#    #+#             */
/*   Updated: 2025/02/04 14:17:49 by nadahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


void	philo_think(t_philosophe *philosophe)
{
	philosophe->etat = PENSER;
	printf("Philosophe %d pense\n", philosophe->id);
	usleep (500);
}

void	philo_eat(t_philosophe *philosophe)
{
	philosophe->etat = MANGER;
	printf("Philosophe %d mange\n", philosophe->id);
	usleep(philosophe->philo->time_to_eat * 1000);
}

void	philo_sleep(t_philosophe *philosophe)
{
	philosophe->etat = DORMIR;
	printf("Philosophe %d dors\n", philosophe->id);
	usleep (philosophe->philo->time_to_sleep * 1000);
}
void	*routine(void *arg)
{
	t_philosophe	*philosophe;
	
	philosophe = (t_philosophe *)arg;
	while (philosophe->etat != MORT && philosophe->nb_meal != philosophe->philo->nbr_of_times_each_philo_must_eat)
	{
		philo_think(philosophe);
		philo_eat(philosophe);
		philo_sleep(philosophe);
	}
	return (NULL);
}

