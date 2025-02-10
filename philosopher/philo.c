/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadahman <nadahman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 10:50:22 by nas               #+#    #+#             */
/*   Updated: 2025/02/10 12:17:20 by nadahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_philo(t_philosophe **philosophe, t_philo *philo)
{
	int	i;

	i = 0;
	gettimeofday(&philo->tmp, NULL);
	philo->start_time = (philo->tmp.tv_sec * 1000) + (philo->tmp.tv_usec
			/ 1000);
	philo->is_dead = 0;
	philo->forks = malloc(sizeof(pthread_mutex_t) * philo->nbr_philo);
	if (!philo->forks)
		return ;
	if (pthread_mutex_init(&philo->print_mutex, NULL) != 0
		|| pthread_mutex_init(&philo->meal_mutex, NULL) != 0
		|| pthread_mutex_init(&philo->is_dead_mutex, NULL) != 0
		|| pthread_mutex_init(&philo->nb_meal_mutex, NULL) != 0)
	{
		free(philo->forks);
		return ;
	}
	while (i < philo->nbr_philo)
	{
		if (pthread_mutex_init(&philo->forks[i], NULL) != 0)
		{
			while (--i >= 0)
				pthread_mutex_destroy(&philo->forks[i]);
			free(philo->forks);
			return ;
		}
		i++;
	}
	i = 0;
	while (i < philo->nbr_philo)
	{
		(*philosophe)[i].id = i + 1;
		(*philosophe)[i].nb_meal = 0;
		(*philosophe)[i].etat = PENSER;
		(*philosophe)[i].last_meal_time = 0;
		(*philosophe)[i].philo = philo;
		(*philosophe)[i].forks_left = &philo->forks[i];
		(*philosophe)[i].forks_right = &philo->forks[(i + 1)
			% philo->nbr_philo];
		i++;
	}
}

void	create_thread(t_philo *philo, t_philosophe *philosophe,
		pthread_t *threads)
{
	int			i;
	pthread_t	monitor_thread;

	if (!philo || !philosophe || !threads)
		return ;
	philo->is_dead = 0;
	i = 0;
	while (i < philo->nbr_philo)
	{
		philosophe[i].philo = philo;
		if (pthread_create(&threads[i], NULL, routine, &philosophe[i]) != 0)
		{
			philo->is_dead = 1;
			return ;
		}
		i++;
	}
	usleep(100);
	if (pthread_create(&monitor_thread, NULL, check_monitoring,
			philosophe) != 0)
	{
		philo->is_dead = 1;
		return ;
	}
	i = 0;
	while (i < philo->nbr_philo)
	{
		pthread_join(threads[i], NULL);
		i++;
	}
	pthread_join(monitor_thread, NULL);
}
