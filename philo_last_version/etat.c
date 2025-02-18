/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   etat.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadahman <nadahman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 13:21:02 by nadahman          #+#    #+#             */
/*   Updated: 2025/02/18 13:29:38 by nadahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_eat(t_philosophe *philosophe)
{
	int	is_dead;

	pthread_mutex_lock(&philosophe->philo->is_dead_mutex);
	is_dead = philosophe->philo->is_dead;
	pthread_mutex_unlock(&philosophe->philo->is_dead_mutex);
	if (is_dead)
		return ;
	check_philo_state(philosophe);
	if (philosophe->philo->nbr_philo == 1)
	{
		one_philo(philosophe);
		return ;
	}
	take_forks(philosophe);
	pthread_mutex_lock(&philosophe->philo->meal_mutex);
	philosophe->last_meal_time = get_time(philosophe->philo);
	pthread_mutex_unlock(&philosophe->philo->meal_mutex);
	eat(philosophe);
	pthread_mutex_lock(&philosophe->philo->nb_meal_mutex);
	philosophe->nb_meal++;
	pthread_mutex_unlock(&philosophe->philo->nb_meal_mutex);
	release_forks(philosophe);
}

void	philo_sleep(t_philosophe *philosophe)
{
	int	is_dead;

	pthread_mutex_lock(&philosophe->philo->is_dead_mutex);
	is_dead = philosophe->philo->is_dead;
	pthread_mutex_unlock(&philosophe->philo->is_dead_mutex);
	if (is_dead)
		return ;
	print_and_lock(philosophe, "is sleeping\n");
	ft_usleep(philosophe->philo->time_to_sleep, philosophe->philo);
}

void	philo_think(t_philosophe *philosophe)
{
	int	is_dead;

	pthread_mutex_lock(&philosophe->philo->is_dead_mutex);
	is_dead = philosophe->philo->is_dead;
	pthread_mutex_unlock(&philosophe->philo->is_dead_mutex);
	if (is_dead)
		return ;
	print_and_lock(philosophe, "is thinking\n");
}

void	check_philo_state(t_philosophe *philosophe)
{
	int	is_dead;

	pthread_mutex_lock(&philosophe->philo->is_dead_mutex);
	is_dead = philosophe->philo->is_dead;
	pthread_mutex_unlock(&philosophe->philo->is_dead_mutex);
	if (is_dead)
		return ;
	if (philosophe->id % 2 == 1)
		ft_usleep(1, philosophe->philo);
	pthread_mutex_lock(&philosophe->philo->meal_mutex);
	if (get_time(philosophe->philo)
		- philosophe->last_meal_time > philosophe->philo->time_to_die)
	{
		pthread_mutex_unlock(&philosophe->philo->meal_mutex);
		return ;
	}
	pthread_mutex_unlock(&philosophe->philo->meal_mutex);
}
