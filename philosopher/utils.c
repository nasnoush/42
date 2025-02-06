/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadahman <nadahman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 11:04:21 by nas               #+#    #+#             */
/*   Updated: 2025/02/06 13:58:06 by nadahman         ###   ########.fr       */
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
	
	while(str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
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
long long int get_time(t_philo *philo)
{
	struct timeval	cur;
	long long int cur_time;

	gettimeofday(&cur, NULL);
	cur_time = (cur.tv_sec * 1000) + (cur.tv_usec / 1000);
	

	return (cur_time - philo->start_time);
}

int is_dead(t_philosophe *philosophe)
{
	long long int cur_time_meal;
	
	cur_time_meal = get_time(philosophe->philo);
	if (cur_time_meal - philosophe->philo->last_meal_time > philosophe->philo->time_to_die)
	{
		philosophe->etat = MORT;
		return (1);
	}
	return (0);
}


// void free_philo(t_philosophe **philosophe)
// {
//     free(*philosophe);
//     *philosophe = NULL;
// }