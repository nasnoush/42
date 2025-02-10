/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadahman <nadahman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 11:04:21 by nas               #+#    #+#             */
/*   Updated: 2025/02/10 11:39:58 by nadahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(char *str)
{
	int	i;
	int	r;
	int	s;

	i = 0;
	r = 0;
	s = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
		{
			s = s * -1;
		}
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		r = r * 10 + (str[i] - 48);
		i++;
	}
	return (r * s);
}

long long int	get_time(t_philo *philo)
{
	struct timeval	cur;
	long long int	cur_time;

	gettimeofday(&cur, NULL);
	cur_time = (cur.tv_sec * 1000) + (cur.tv_usec / 1000);
	return (cur_time - philo->start_time);
}

int	is_dead(t_philosophe *philosophe)
{
	long long int	cur_time_meal;

	cur_time_meal = get_time(philosophe->philo);
	if (cur_time_meal
		- philosophe->last_meal_time > philosophe->philo->time_to_die)
	{
		philosophe->etat = MORT;
		return (1);
	}
	return (0);
}

void	destroy_mutex(t_philosophe *philosophe)
{
	int	i;

	i = 0;
	while (i < philosophe->philo->nbr_philo)
	{
		pthread_mutex_destroy(&philosophe->philo->forks[i]);
		i++;
	}
	pthread_mutex_destroy(&philosophe->philo->print_mutex);
	pthread_mutex_destroy(&philosophe->philo->meal_mutex);
	pthread_mutex_destroy(&philosophe->philo->is_dead_mutex);
	pthread_mutex_destroy(&philosophe->philo->nb_meal_mutex);
	free(philosophe->philo->forks);
}

void	print_and_lock(t_philosophe *philosophe, char *str)
{
	int	is_dead;

	pthread_mutex_lock(&philosophe->philo->is_dead_mutex);
	is_dead = philosophe->philo->is_dead;
	pthread_mutex_unlock(&philosophe->philo->is_dead_mutex);
	if (!is_dead)
	{
		pthread_mutex_lock(&philosophe->philo->print_mutex);
		printf("%lld %d %s", get_time(philosophe->philo), philosophe->id, str);
		pthread_mutex_unlock(&philosophe->philo->print_mutex);
	}
}

void	free_all(t_philosophe *philosophe)
{
	free(philosophe->philo);
	free(philosophe);
	free(philosophe->philo->threads);
}
