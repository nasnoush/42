/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadahman <nadahman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 12:38:34 by nadahman          #+#    #+#             */
/*   Updated: 2025/02/06 14:00:59 by nadahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_think(t_philosophe *philosophe)
{
	philosophe->etat = PENSER;
	pthread_mutex_lock(&philosophe->philo->print_mutex);
	printf("%lld %d is thinking\n", get_time(philosophe->philo), philosophe->id);
	pthread_mutex_unlock(&philosophe->philo->print_mutex);
	usleep (500);
}

void	philo_eat(t_philosophe *philosophe)
{
	philosophe->etat = MANGER;
	if (philosophe->id % 2 == 0)
	{
		pthread_mutex_lock(philosophe->forks_left);
		pthread_mutex_lock(&philosophe->philo->print_mutex);
		printf("%lld %d has taken a fork left\n", get_time(philosophe->philo), philosophe->id);
		pthread_mutex_unlock(&philosophe->philo->print_mutex);
		pthread_mutex_lock(philosophe->forks_right);
		pthread_mutex_lock(&philosophe->philo->print_mutex);
		printf("%lld %d has taken a fork right\n", get_time(philosophe->philo), philosophe->id);
		pthread_mutex_unlock(&philosophe->philo->print_mutex);
		pthread_mutex_lock(&philosophe->philo->print_mutex);
		printf("%lld %d is eating\n", get_time(philosophe->philo), philosophe->id);
		pthread_mutex_unlock(&philosophe->philo->print_mutex);
		philosophe->nb_meal++;
		philosophe->philo->last_meal_time = get_time(philosophe->philo);
	}
	else
	{
		pthread_mutex_lock(philosophe->forks_right);
		pthread_mutex_lock(&philosophe->philo->print_mutex);
		printf("%lld %d has taken a fork right\n", get_time(philosophe->philo), philosophe->id);
		pthread_mutex_unlock(&philosophe->philo->print_mutex);
		pthread_mutex_lock(philosophe->forks_left);
		pthread_mutex_lock(&philosophe->philo->print_mutex);
		printf("%lld %d has taken a fork left\n", get_time(philosophe->philo), philosophe->id);
		pthread_mutex_unlock(&philosophe->philo->print_mutex);
		pthread_mutex_lock(&philosophe->philo->print_mutex);
		printf("%lld %d is eating\n", get_time(philosophe->philo), philosophe->id);
		pthread_mutex_unlock(&philosophe->philo->print_mutex);
		philosophe->nb_meal++;
		philosophe->philo->last_meal_time = get_time(philosophe->philo);
	}
	usleep(philosophe->philo->time_to_eat * 1000);
	pthread_mutex_unlock(philosophe->forks_left);
	pthread_mutex_unlock(philosophe->forks_right);
}

void	philo_sleep(t_philosophe *philosophe)
{
	philosophe->etat = DORMIR;
	pthread_mutex_lock(&philosophe->philo->print_mutex);
	printf("%lld %d is sleeping\n", get_time(philosophe->philo), philosophe->id);
	pthread_mutex_unlock(&philosophe->philo->print_mutex);
	usleep (philosophe->philo->time_to_sleep * 1000);
}
void	*routine(void *arg)
{
	t_philosophe	*philosophe;
	
	philosophe = (t_philosophe *)arg;
	while (1)
	{
		if (philosophe->nb_meal == philosophe->philo->nbr_of_times_each_philo_must_eat)
			break ;
		if (is_dead(philosophe) == 1)
		{
			pthread_mutex_lock(&philosophe->philo->print_mutex);
			printf("%lld %d died\n", get_time(philosophe->philo), philosophe->id);
			pthread_mutex_unlock(&philosophe->philo->print_mutex);
			exit (1);
		}
		philo_think(philosophe);
		philo_eat(philosophe);
		philo_sleep(philosophe);
	}
	return (NULL);
}

