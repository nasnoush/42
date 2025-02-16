/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nas <nas@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 11:30:57 by nas               #+#    #+#             */
/*   Updated: 2025/02/16 12:26:23 by nas              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void init_main(char **argv, t_philo *philo, t_philosophe **philosophe, pthread_t **threads)
{
    philo->nbr_philo = ft_atoi(argv[1]);
    philo->time_to_die = ft_atoi(argv[2]);
    philo->time_to_eat = ft_atoi(argv[3]);
    philo->time_to_sleep = ft_atoi(argv[4]);
    
    *philosophe = malloc(sizeof(t_philosophe) * philo->nbr_philo);
    if (*philosophe == NULL)
        return;
    
    *threads = malloc(sizeof(pthread_t) * philo->nbr_philo);
    if (*threads == NULL)
    {
        free(*philosophe);
        *philosophe = NULL;
        return;
    }
}

// int main(int argc, char **argv)
// {
//     t_philo *philo;
//     t_philosophe *philosophe;
//     pthread_t *threads;

//     if (argc != 5 && argc != 6)
//     {
//         printf("Error: Pas assez d'arguments\n");
//         return (1);
//     }
//     philo = malloc(sizeof(t_philo));
//     if (philo == NULL)
//         return (1);
//     init_main(argv, philo, &philosophe, &threads);
//     if (philosophe == NULL || threads == NULL)
//     {
//         free(philo);
//         return (1);
//     }
//     if (!check_arg_num(argv) || !check_args(argc, argv))
//     {
//         free_all(philo, philosophe, threads);
//         return (1);
//     }
//     if (argc == 6)
//         philo->nbr_of_times_each_philo_must_eat = ft_atoi(argv[5]);
//     else
//         philo->nbr_of_times_each_philo_must_eat = -1;
//     init_philo(&philosophe, philo);
//     create_thread(philo, philosophe, threads);
//     destroy_mutex(philosophe);
//     free_all(philo, philosophe, threads);
//     return (0);
// }

int	init_and_validate(int argc, char **argv, t_philo **philo, t_philosophe **philosophe, pthread_t **threads)
{
	if (argc != 5 && argc != 6)
		return (printf("Error: Pas assez d'arguments\n"), 1);
	*philo = malloc(sizeof(t_philo));
	if (!(*philo))
		return (1);
	init_main(argv, *philo, philosophe, threads);
	if (!(*philosophe) || !(*threads))
		return (free(*philo), 1);
	if (!check_arg_num(argv) || !check_args(argc, argv))
		return (free_all(*philo, *philosophe, *threads), 1);
	if (argc == 6)
		(*philo)->nbr_of_times_each_philo_must_eat = ft_atoi(argv[5]);
	else
		(*philo)->nbr_of_times_each_philo_must_eat = -1;
	return (0);
}

int	main(int argc, char **argv)
{
	t_philo			*philo;
	t_philosophe	*philosophe;
	pthread_t		*threads;

	if (init_and_validate(argc, argv, &philo, &philosophe, &threads))
		return (1);
	init_philo(&philosophe, philo);
	create_thread(philo, philosophe, threads);
	destroy_mutex(philosophe);
	free_all(philo, philosophe, threads);
	return (0);
}

