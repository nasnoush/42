/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nas <nas@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 12:38:34 by nadahman          #+#    #+#             */
/*   Updated: 2025/02/09 18:36:52 by nas              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void philo_think(t_philosophe *philosophe)
{
    int is_dead;

    pthread_mutex_lock(&philosophe->philo->is_dead_mutex);
    is_dead = philosophe->philo->is_dead;
    pthread_mutex_unlock(&philosophe->philo->is_dead_mutex);
    if (is_dead)
        return;
    philosophe->etat = PENSER;
    print_and_lock(philosophe, "is thinking\n");
    usleep(500);
}

void philo_eat(t_philosophe *philosophe)
{
    int is_dead;

    pthread_mutex_lock(&philosophe->philo->is_dead_mutex);
    is_dead = philosophe->philo->is_dead;
    pthread_mutex_unlock(&philosophe->philo->is_dead_mutex);
    if (is_dead)
        return;
     if (philosophe->philo->nbr_philo == 1)
    {
            pthread_mutex_lock(philosophe->forks_left);
            print_and_lock(philosophe, "has taken a fork\n");
            usleep(philosophe->philo->time_to_die * 1000);
            pthread_mutex_lock(&philosophe->philo->is_dead_mutex);
            philosophe->philo->is_dead = 1;
            pthread_mutex_unlock(&philosophe->philo->is_dead_mutex);
            print_and_lock(philosophe, "died");
            pthread_mutex_unlock(philosophe->forks_left);
            return;
     }
    pthread_mutex_lock(philosophe->forks_left);
    print_and_lock(philosophe, "has taken a fork\n");
    pthread_mutex_lock(philosophe->forks_right);
    print_and_lock(philosophe, "has taken a fork\n");

    pthread_mutex_lock(&philosophe->philo->meal_mutex);
    philosophe->last_meal_time = get_time(philosophe->philo);
    pthread_mutex_unlock(&philosophe->philo->meal_mutex);

    print_and_lock(philosophe, "is eating\n");

    pthread_mutex_lock(&philosophe->philo->nb_meal_mutex);
    philosophe->nb_meal++;
    pthread_mutex_unlock(&philosophe->philo->nb_meal_mutex);

    usleep(philosophe->philo->time_to_eat * 1000);

    pthread_mutex_unlock(philosophe->forks_right);
    pthread_mutex_unlock(philosophe->forks_left);
}

void philo_sleep(t_philosophe *philosophe)
{
    int is_dead;
    
    pthread_mutex_lock(&philosophe->philo->is_dead_mutex);
    is_dead = philosophe->philo->is_dead;
    pthread_mutex_unlock(&philosophe->philo->is_dead_mutex);
    if (is_dead)
        return;
    philosophe->etat = DORMIR;
    print_and_lock(philosophe, "is sleeping\n");
    usleep(philosophe->philo->time_to_sleep * 1000);
}

void *routine(void *arg)
{
    t_philosophe *philosophe;

    philosophe = (t_philosophe *)arg;
    pthread_mutex_lock(&philosophe->philo->meal_mutex);
    philosophe->last_meal_time = get_time(philosophe->philo);
    pthread_mutex_unlock(&philosophe->philo->meal_mutex);
    if (philosophe->id % 2 == 0)
        usleep(philosophe->philo->time_to_eat * 500);
    while (1)
    {
        pthread_mutex_lock(&philosophe->philo->is_dead_mutex);
        philosophe->philo->philo_dead = philosophe->philo->is_dead;
        pthread_mutex_unlock(&philosophe->philo->is_dead_mutex);
        if (philosophe->philo->philo_dead)
            return NULL;
        pthread_mutex_lock(&philosophe->philo->nb_meal_mutex);
        if (philosophe->philo->nbr_of_times_each_philo_must_eat != -1 &&
            philosophe->nb_meal >= philosophe->philo->nbr_of_times_each_philo_must_eat)
        {
            pthread_mutex_unlock(&philosophe->philo->nb_meal_mutex);
            return NULL;
        }
        pthread_mutex_unlock(&philosophe->philo->nb_meal_mutex);
        philo_think(philosophe);
        philo_eat(philosophe);
        philo_sleep(philosophe);
    }
    return NULL;
}
