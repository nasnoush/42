/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadahman <nadahman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 10:50:22 by nas               #+#    #+#             */
/*   Updated: 2025/02/03 13:21:04 by nadahman         ###   ########.fr       */
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
        i++;
    }
}

void	init_forks(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->nbr_philo)
	{
		
	}
}

void	*routine(void *arg)
{
	t_philosophe	*philosophe;
	
	while (1)
	{
		if (philosophe->etat == MORT)
			break ;
		if (philosophe->etat == PENSER)
			printf("Philosophe %d pense", (*philosophe).id);
		if (philosophe->etat == MANGER)
		{
			printf("Philosophe %d mange", (*philosophe).id);
		}
		if (philosophe->etat == DORMIR)
			printf("Philosophe %d dors", (*philosophe).id);
	}

}
void	create_thread(t_philo *philo)
{
	t_philosophe *philosophe;
	int	i;
	
	i = 0;
	while (i < philo->nbr_philo)
	{
		pthread_create();
		i++;
		    dormir(philo);
    }
}