/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadahman <nadahman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 12:15:12 by nas               #+#    #+#             */
/*   Updated: 2025/02/18 13:28:00 by nadahman         ###   ########.fr       */
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
