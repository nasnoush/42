/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadahman <nadahman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 12:11:55 by nas               #+#    #+#             */
/*   Updated: 2025/02/18 10:27:04 by nadahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_all(t_philo *philo, t_philosophe *philosophe, pthread_t *threads)
{
	free(philo);
	free(philosophe);
	free(threads);
}

void	ft_usleep(long long wait_time, t_philo *philo)
{
	long long	start_time;
	long long	cur_time;
	long long	tmp_ecoule;

	start_time = get_time(philo);
	while (1)
	{
		cur_time = get_time(philo);
		tmp_ecoule = cur_time - start_time;
		if (tmp_ecoule >= wait_time)
			break ;
		usleep(100);
	}
}
