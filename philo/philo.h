/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadahman <nadahman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 10:52:05 by nas               #+#    #+#             */
/*   Updated: 2025/02/17 12:04:35 by nadahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <limits.h>
# include <pthread.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

typedef struct s_philo
{
	int				nbr_philo;
	long long int	start_time;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nbr_of_times_each_philo_must_eat;
	pthread_t		*threads;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	time;
	pthread_mutex_t	meal_mutex;
	pthread_mutex_t	is_dead_mutex;
	pthread_mutex_t	nb_meal_mutex;
	int				is_dead;
	int				meals_count;
	int				philo_dead;
	struct timeval	tmp;

}					t_philo;

typedef enum e_etat
{
	PENSER,
	MANGER,
	DORMIR,
	MORT,
}					t_etat;

typedef struct s_philosophe
{
	int				id;
	int				nb_meal;
	t_etat			etat;
	pthread_mutex_t	*forks_left;
	pthread_mutex_t	*forks_right;
	long long int	last_meal_time;
	t_philo			*philo;

}					t_philosophe;

typedef struct s_data
{
	t_philo			*philo;
	t_philosophe	*philosophe;
	pthread_t		*threads;
}					t_data;

int					ft_atoi(char *str);
void				free_philo(t_philosophe *philosophe);
void				init_philo(t_philosophe **philosophe, t_philo *philo);
void				*routine(void *arg);
void				create_thread(t_philo *philo, t_philosophe *philosophe,
						pthread_t *threads);
long long int		get_time(t_philo *philo);
int					is_finish(t_philosophe *philosophe);
int					is_dead(t_philosophe *philosophe);
void				destroy_mutex(t_philosophe *philosophe);
void				philo_eat(t_philosophe *philosophe);
void				philo_sleep(t_philosophe *philosophe);
int					check_args(int argc, char **argv);
int					check_arg_num(char **argv);
void				init_main(char **argv, t_philo *philo,
						t_philosophe **philosophe, pthread_t **threads);
void				print_and_lock(t_philosophe *philosophe, char *str);
void				*check_monitoring(void *arg);
void				take_forks(t_philosophe *philosophe);
void				release_forks(t_philosophe *philosophe);
int					check_death(t_philosophe *philosophe);
void				update_meal_time(t_philosophe *philosophe);
void				free_all(t_philo *philo, t_philosophe *philosophe,
						pthread_t *threads);
int					create_philo_threads(t_philo *philo,
						t_philosophe *philosophe, pthread_t *threads);
void				create_thread(t_philo *philo, t_philosophe *philosophe,
						pthread_t *threads);
void				release_forks(t_philosophe *philosophe);
void				philo_think(t_philosophe *philosophe);
void				philo_eat(t_philosophe *philosophe);
void				philo_sleep(t_philosophe *philosophe);
void				one_philo(t_philosophe *philosophe);
void				eat(t_philosophe *philosophe);
void				update_meal_time(t_philosophe *philosophe);
int					check_meals(t_philosophe *philosophe);
int					check_death(t_philosophe *philosophe);
int					check_args(int argc, char **argv);
int					check_arg_num(char **argv);
int					init_forks(t_philo *philo);
int					init_mutexes(t_philo *philo);
void				ft_usleep(long long wait_time, t_philo *philo);

#endif