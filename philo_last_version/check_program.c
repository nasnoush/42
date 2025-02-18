/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_program.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadahman <nadahman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 15:53:28 by nas               #+#    #+#             */
/*   Updated: 2025/02/18 13:29:51 by nadahman         ###   ########.fr       */
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
	int	philo_fini;

	if (philosophe->philo->nbr_of_times_each_philo_must_eat == -1)
		return (0);
	i = 0;
	philo_fini = 0;
	while (i < philosophe->philo->nbr_philo)
	{
		pthread_mutex_lock(&philosophe->philo->nb_meal_mutex);
		if (philosophe[i].nb_meal
			>= philosophe->philo->nbr_of_times_each_philo_must_eat)
			philo_fini++;
		pthread_mutex_unlock(&philosophe->philo->nb_meal_mutex);
		i++;
	}
	if (philo_fini == philosophe->philo->nbr_philo)
	{
		pthread_mutex_lock(&philosophe->philo->stop_mutex);
		philosophe->philo->stop_tout = 1;
		pthread_mutex_unlock(&philosophe->philo->stop_mutex);
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

void	condition_stop_tout(t_philosophe *philosophe)
{
	if (philosophe->philo->stop_tout == 1 || philosophe->philo->is_dead == 1)
	{
		pthread_mutex_unlock(&philosophe->philo->stop_mutex);
		pthread_mutex_unlock(&philosophe->philo->is_dead_mutex);
		return ;
	}
}

void	boucle_routine(t_philosophe *philosophe)
{
	while (1)
	{
		pthread_mutex_lock(&philosophe->philo->stop_mutex);
		pthread_mutex_lock(&philosophe->philo->is_dead_mutex);
		condition_stop_tout(philosophe);
		pthread_mutex_unlock(&philosophe->philo->stop_mutex);
		pthread_mutex_unlock(&philosophe->philo->is_dead_mutex);
		philo_think(philosophe);
		philo_eat(philosophe);
		pthread_mutex_lock(&philosophe->philo->nb_meal_mutex);
		if (philosophe->philo->nbr_of_times_each_philo_must_eat != -1
			&& philosophe->nb_meal
			>= philosophe->philo->nbr_of_times_each_philo_must_eat)
		{
			pthread_mutex_unlock(&philosophe->philo->nb_meal_mutex);
			return ;
		}
		pthread_mutex_unlock(&philosophe->philo->nb_meal_mutex);
		philo_sleep(philosophe);
	}
}
