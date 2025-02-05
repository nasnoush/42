/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadahman <nadahman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 12:38:34 by nadahman          #+#    #+#             */
/*   Updated: 2025/02/05 14:02:00 by nadahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// void	is_dead(t_philosophe **philosophe)
// {
// 	if ()
// }

void	philo_think(t_philosophe *philosophe)
{
	philosophe->etat = PENSER;
	pthread_mutex_lock(&philosophe->philo->print_mutex);
	printf("%d is thinking\n", philosophe->id);
	pthread_mutex_unlock(&philosophe->philo->print_mutex);
	usleep (500);
}

void	philo_eat(t_philosophe *philosophe)
{
	philosophe->etat = MANGER;
	pthread_mutex_lock(&philosophe->philo->print_mutex);
	printf("%d is eating\n", philosophe->id);
	pthread_mutex_unlock(&philosophe->philo->print_mutex);
	if (philosophe->id % 2 == 0)
	{
		pthread_mutex_lock(philosophe->forks_left);
		pthread_mutex_lock(&philosophe->philo->print_mutex);
		printf("%d has taken a fork\n", philosophe->id);
		pthread_mutex_unlock(&philosophe->philo->print_mutex);
		pthread_mutex_lock(philosophe->forks_right);
		pthread_mutex_lock(&philosophe->philo->print_mutex);
		printf("%d has taken a fork\n", philosophe->id);
		pthread_mutex_unlock(&philosophe->philo->print_mutex);
	}
	else
	{
		pthread_mutex_lock(philosophe->forks_right);
		pthread_mutex_lock(&philosophe->philo->print_mutex);
		printf("%d has taken a fork\n", philosophe->id);
		pthread_mutex_unlock(&philosophe->philo->print_mutex);
		pthread_mutex_lock(philosophe->forks_left);
		pthread_mutex_lock(&philosophe->philo->print_mutex);
		printf("%d has taken a fork\n", philosophe->id);
		pthread_mutex_unlock(&philosophe->philo->print_mutex);
	}
	pthread_mutex_unlock(philosophe->forks_left);
	pthread_mutex_unlock(philosophe->forks_right);
	usleep(philosophe->philo->time_to_eat * 1000);
}

void	philo_sleep(t_philosophe *philosophe)
{
	philosophe->etat = DORMIR;
	pthread_mutex_lock(&philosophe->philo->print_mutex);
	printf("%d is sleeping\n", philosophe->id);
	pthread_mutex_unlock(&philosophe->philo->print_mutex);
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

