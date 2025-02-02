/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nas <nas@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 10:50:22 by nas               #+#    #+#             */
/*   Updated: 2025/02/02 10:27:17 by nas              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void init_philo(t_philosophe **philosophe, t_philo *philo)
{
    int i;

    *philosophe = malloc(sizeof(t_philosophe) * philo->nbr_philo);
    if (*philosophe == NULL)
        return;

    i = 0;
    while (i < philo->nbr_philo)
    {
        (*philosophe)[i].id = i + 1;
        (*philosophe)[i].nb_meal = 0;
        (*philosophe)[i].etat = PENSER;
        pthread_mutex_init(&((*philosophe)[i].mutex), NULL);
        i++;
    }
}

void	init_mutex(t_philo *philo, t_philosophe **philosophe)
{
	int	i;

	i = 0;
	philo->mutex = malloc(sizeof(pthread_mutex_t) * philo->nbr_philo);
	if (philo->mutex == NULL)
		return ;
	while (i < philo->nbr_philo)
	{
		pthread_mutex_init(philo->mutex[i], NULL);
		i++;
		if (pthread_mutex_init(philo->mutex, NULL) == 0)
		{
			free_philo(*philosophe);
			exit (1);
		}
	}
}

void	create_thread(t_philo *philo)
{
	int	i;

	philo->threads = malloc(sizeof(pthread_t) * philo->nbr_philo);
	if (philo->threads == NULL)
		return (NULL);
	i = 0;
	while (i < philo->nbr_philo)
	{
		pthread_create(&philo->threads[i], NULL, routine, (void *)&philo->);
		i++;
	}
}

void	*routine(void *arg)
{
	
}