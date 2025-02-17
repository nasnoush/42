/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadahman <nadahman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 15:53:28 by nas               #+#    #+#             */
/*   Updated: 2025/02/17 10:10:47 by nadahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_death(t_philosophe *philo)
{
	long long	current_time;

	pthread_mutex_lock(&philo->philo->meal_mutex);
	current_time = get_time(philo->philo);
	if ((current_time - philo->last_meal_time) > philo->philo->time_to_die)
	{
		print_and_lock(philo, "died\n");
		pthread_mutex_lock(&philo->philo->is_dead_mutex);
		philo->philo->is_dead = 1;
		pthread_mutex_unlock(&philo->philo->is_dead_mutex);
		pthread_mutex_unlock(&philo->philo->meal_mutex);
		return (1);
	}
	pthread_mutex_unlock(&philo->philo->meal_mutex);
	return (0);
}

int	check_meals(t_philosophe *philosophe)
{
	int	i;
	int	total_finished;

	if (philosophe->philo->nbr_of_times_each_philo_must_eat == -1)
		return (0);
	i = 0;
	total_finished = 0;
	while (i < philosophe->philo->nbr_philo)
	{
		pthread_mutex_lock(&philosophe->philo->nb_meal_mutex);
		if (philosophe[i].nb_meal
			>= philosophe->philo->nbr_of_times_each_philo_must_eat)
			total_finished++;
		pthread_mutex_unlock(&philosophe->philo->nb_meal_mutex);
		i++;
	}
	if (total_finished == philosophe->philo->nbr_philo)
	{
		pthread_mutex_lock(&philosophe->philo->is_dead_mutex);
		philosophe->philo->is_dead = 1;
		pthread_mutex_unlock(&philosophe->philo->is_dead_mutex);
		return (1);
	}
	return (0);
}

void	*check_monitoring(void *arg)
{
	t_philosophe	*philosophe;
	int				i;

	philosophe = (t_philosophe *)arg;
	if (!philosophe)
		return (NULL);
	usleep(100);
	while (1)
	{
		i = 0;
		while (i < philosophe->philo->nbr_philo)
		{
			if (check_death(&philosophe[i]) || check_meals(philosophe))
				return (NULL);
			i++;
		}
	}
	return (NULL);
}

void	*routine(void *arg)
{
	t_philosophe	*philosophe;
	int				is_dead;

	philosophe = (t_philosophe *)arg;
	if (!philosophe)
		return (NULL);
	pthread_mutex_lock(&philosophe->philo->meal_mutex);
	philosophe->last_meal_time = get_time(philosophe->philo);
	pthread_mutex_unlock(&philosophe->philo->meal_mutex);
	if (philosophe->id % 2)
		usleep(1000);
	while (1)
	{
		pthread_mutex_lock(&philosophe->philo->is_dead_mutex);
		is_dead = philosophe->philo->is_dead;
		pthread_mutex_unlock(&philosophe->philo->is_dead_mutex);
		if (is_dead)
			return (NULL);
		philo_think(philosophe);
		philo_eat(philosophe);
		philo_sleep(philosophe);
	}
	return (NULL);
}
