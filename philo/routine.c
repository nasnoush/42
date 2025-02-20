/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadahman <nadahman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 12:38:34 by nadahman          #+#    #+#             */
/*   Updated: 2025/02/19 13:03:47 by nadahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	one_philo(t_philosophe *philosophe)
{
	pthread_mutex_lock(philosophe->forks_left);
	print_and_lock(philosophe, "has taken a fork\n");
	ft_usleep(philosophe->philo->time_to_die, philosophe->philo);
	pthread_mutex_unlock(philosophe->forks_left);
	return ;
}

void	take_forks(t_philosophe *philosophe)
{
	pthread_mutex_lock(&philosophe->philo->is_dead_mutex);
	if (philosophe->philo->is_dead)
	{
		pthread_mutex_unlock(&philosophe->philo->is_dead_mutex);
		return ;
	}
	pthread_mutex_unlock(&philosophe->philo->is_dead_mutex);
	if (philosophe->id % 2 == 0)
	{
		pthread_mutex_lock(philosophe->forks_right);
		print_and_lock(philosophe, "has taken a fork\n");
		pthread_mutex_lock(philosophe->forks_left);
	}
	else
	{
		ft_usleep(1, philosophe->philo);
		pthread_mutex_lock(philosophe->forks_left);
		print_and_lock(philosophe, "has taken a fork\n");
		pthread_mutex_lock(philosophe->forks_right);
	}
	print_and_lock(philosophe, "has taken a fork\n");
}

void	release_forks(t_philosophe *philosophe)
{
	if (philosophe->id % 2 == 0)
	{
		pthread_mutex_unlock(philosophe->forks_left);
		pthread_mutex_unlock(philosophe->forks_right);
	}
	else
	{
		pthread_mutex_unlock(philosophe->forks_right);
		pthread_mutex_unlock(philosophe->forks_left);
	}
}

void	eat(t_philosophe *philosophe)
{
	print_and_lock(philosophe, "is eating\n");
	pthread_mutex_lock(&philosophe->philo->meal_mutex);
	philosophe->last_meal_time = get_time(philosophe->philo);
	pthread_mutex_unlock(&philosophe->philo->meal_mutex);
	ft_usleep(philosophe->philo->time_to_eat, philosophe->philo);
}

void	*routine(void *arg)
{
	t_philosophe	*philosophe;

	philosophe = (t_philosophe *)arg;
	if (!philosophe)
		return (NULL);
	pthread_mutex_lock(&philosophe->philo->meal_mutex);
	philosophe->last_meal_time = get_time(philosophe->philo);
	pthread_mutex_unlock(&philosophe->philo->meal_mutex);
	if (philosophe->id % 2)
		ft_usleep(1, philosophe->philo);
	boucle_routine(philosophe);
	return (NULL);
}
