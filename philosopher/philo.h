/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadahman <nadahman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 10:52:05 by nas               #+#    #+#             */
/*   Updated: 2025/02/06 13:53:14 by nadahman         ###   ########.fr       */
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
	long long int start_time;
	long long	int	last_meal_time;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	nbr_of_times_each_philo_must_eat;
	pthread_t	*threads;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	time;
	
	
	
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
	pthread_mutex_t	*forks_left;
	pthread_mutex_t	*forks_right;
	t_philo *philo;
	
}t_philosophe;


int				ft_atoi(char *str);
void			free_philo(t_philosophe *philosophe);
void			init_philo(t_philosophe **philosophe, t_philo *philo);
void			*routine(void *arg);
void			create_thread(t_philo *philo, t_philosophe *philosophe, pthread_t *threads);
long long int 	get_time(t_philo *philo);
int			is_finish(t_philosophe *philosophe);
int is_dead(t_philosophe *philosophe);




#endif