/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadahman <nadahman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 10:52:05 by nas               #+#    #+#             */
/*   Updated: 2025/02/03 13:12:25 by nadahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <pthread.h>


typedef struct s_philo
{
	int	nbr_philo;
	int	forks;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	nbr_of_times_each_philo_must_eat;
	pthread_t	*threads;
	pthread_mutex_t	*mutex;
	
	
}t_philo;

typedef enum e_etat
{
	PENSER,
	MANGER,
	DORMIR,
	MORT,
}t_etat;

typedef struct s_philosophe
{
	int	id;
	int	nb_meal;
	t_etat etat;
	pthread_mutex_t	mutex;
}t_philosophe;


int	ft_atoi(char *str);
void free_philo(t_philosophe **philosophe);

#endif