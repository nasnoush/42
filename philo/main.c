/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadahman <nadahman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 11:30:57 by nas               #+#    #+#             */
/*   Updated: 2025/02/17 11:25:17 by nadahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_main(char **argv, t_philo *philo, t_philosophe **philosophe,
		pthread_t **threads)
{
	philo->nbr_philo = ft_atoi(argv[1]);
	philo->time_to_die = ft_atoi(argv[2]);
	philo->time_to_eat = ft_atoi(argv[3]);
	philo->time_to_sleep = ft_atoi(argv[4]);
	*philosophe = malloc(sizeof(t_philosophe) * philo->nbr_philo);
	if (*philosophe == NULL)
		return ;
	*threads = malloc(sizeof(pthread_t) * philo->nbr_philo);
	if (*threads == NULL)
	{
		free(*philosophe);
		*philosophe = NULL;
		return ;
	}
}

int	init_and_validate(int argc, char **argv, t_data *data)
{
	if (argc != 5 && argc != 6)
		return (printf("Error: Pas assez d'arguments\n"), 1);
	data->philo = malloc(sizeof(t_philo));
	if (!data->philo)
		return (1);
	init_main(argv, data->philo, &(data->philosophe), &(data->threads));
	if (!data->philosophe || !data->threads)
		return (free(data->philo), 1);
	if (!check_arg_num(argv) || !check_args(argc, argv))
		return (free_all(data->philo, data->philosophe, data->threads), 1);
	if (argc == 6)
		data->philo->nbr_of_times_each_philo_must_eat = ft_atoi(argv[5]);
	else
		data->philo->nbr_of_times_each_philo_must_eat = -1;
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (init_and_validate(argc, argv, &data))
		return (1);
	init_philo(&(data.philosophe), data.philo);
	create_thread(data.philo, data.philosophe, data.threads);
	destroy_mutex(data.philosophe);
	free_all(data.philo, data.philosophe, data.threads);
	return (0);
}
