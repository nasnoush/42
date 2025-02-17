/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadahman <nadahman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 12:15:12 by nas               #+#    #+#             */
/*   Updated: 2025/02/17 13:23:33 by nadahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	create_philo_threads(t_philo *philo, t_philosophe *philosophe,
		pthread_t *threads)
{
	int	i;

	i = 0;
	while (i < philo->nbr_philo)
	{
		philosophe[i].philo = philo;
		if (pthread_create(&threads[i], NULL, routine, &philosophe[i]) != 0)
		{
			philo->is_dead = 1;
			return (1);
		}
		i++;
	}
	return (0);
}

void	create_thread(t_philo *philo, t_philosophe *philosophe,
		pthread_t *threads)
{
	int			i;
	pthread_t	monitor_thread;

	if (!philo || !philosophe || !threads)
		return ;
	philo->is_dead = 0;
	if (create_philo_threads(philo, philosophe, threads))
		return ;
	if (pthread_create(&monitor_thread, NULL, check_monitoring,
			philosophe) != 0)
	{
		philo->is_dead = 1;
		return ;
	}
	i = 0;
	while (i < philo->nbr_philo)
		pthread_join(threads[i++], NULL);
	pthread_join(monitor_thread, NULL);
}

void	take_forks(t_philosophe *philosophe)
{
	if (philosophe->id % 2 == 0)
	{
		pthread_mutex_lock(philosophe->forks_right);
		print_and_lock(philosophe, "has taken a fork\n");
		pthread_mutex_lock(philosophe->forks_left);
	}
	else
	{
		pthread_mutex_lock(philosophe->forks_left);
		print_and_lock(philosophe, "has taken a fork\n");
		pthread_mutex_lock(philosophe->forks_right);
	}
	print_and_lock(philosophe, "has taken a fork\n");
}

void	release_forks(t_philosophe *philosophe)
{
	pthread_mutex_unlock(philosophe->forks_right);
	pthread_mutex_unlock(philosophe->forks_left);
}

void	eat(t_philosophe *philosophe)
{
	print_and_lock(philosophe, "is eating\n");
	usleep(philosophe->philo->time_to_eat * 1000);
}
