/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadahman <nadahman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 15:53:28 by nas               #+#    #+#             */
/*   Updated: 2025/02/11 10:43:38 by nadahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// void	*check_monitoring(void *arg)
// {
// 	t_philosophe	*philosophe;
// 	int				i;
// 	long long		current_time;

// 	philosophe = (t_philosophe *)arg;
// 	if (!philosophe)
// 		return (NULL);
// 	usleep(100);
// 	while (1)
// 	{
// 		i = 0;
// 		philosophe->philo->meals_count = 0;
// 		while (i < philosophe->philo->nbr_philo)
// 		{
// 			pthread_mutex_lock(&philosophe->philo->meal_mutex);
// 			current_time = get_time(philosophe->philo);
// 			if ((current_time
// 					- philosophe[i].last_meal_time) >= philosophe->philo->time_to_die)
// 			{
// 				print_and_lock(&philosophe[i], "died\n");
// 				pthread_mutex_lock(&philosophe->philo->is_dead_mutex);
// 				philosophe->philo->is_dead = 1;
// 				pthread_mutex_unlock(&philosophe->philo->is_dead_mutex);
// 				pthread_mutex_unlock(&philosophe->philo->meal_mutex);
// 				return (NULL);
// 			}
// 			pthread_mutex_unlock(&philosophe->philo->meal_mutex);
// 			if (philosophe->philo->nbr_of_times_each_philo_must_eat != -1)
// 			{
// 				pthread_mutex_lock(&philosophe->philo->nb_meal_mutex);
// 				if (philosophe[i].nb_meal >= philosophe->philo->nbr_of_times_each_philo_must_eat)
// 					philosophe->philo->meals_count++;
// 				pthread_mutex_unlock(&philosophe->philo->nb_meal_mutex);
// 			}
// 			i++;
// 		}
// 		if (philosophe->philo->nbr_of_times_each_philo_must_eat != -1
// 			&& philosophe->philo->meals_count == philosophe->philo->nbr_philo)
// 		{
// 			pthread_mutex_lock(&philosophe->philo->is_dead_mutex);
// 			philosophe->philo->is_dead = 1;
// 			pthread_mutex_unlock(&philosophe->philo->is_dead_mutex);
// 			return (NULL);
// 		}
// 		usleep(100);
// 	}
// 	return (NULL);
// }

// void *check_monitoring(void *arg)
// {
//     t_philosophe *philosophe;
//     int i;
//     long long current_time;
    
//     philosophe = (t_philosophe *)arg;
//     if (!philosophe)
//         return (NULL);
//     usleep(100);
    
//     while (1)
//     {
//         i = 0;
//         int total_finished = 0;
        
//         while (i < philosophe->philo->nbr_philo)
//         {
//             pthread_mutex_lock(&philosophe->philo->meal_mutex);
//             current_time = get_time(philosophe->philo);
//             if ((current_time - philosophe[i].last_meal_time) >= philosophe->philo->time_to_die)
//             {
//                 print_and_lock(&philosophe[i], "died\n");
//                 pthread_mutex_lock(&philosophe->philo->is_dead_mutex);
//                 philosophe->philo->is_dead = 1;
//                 pthread_mutex_unlock(&philosophe->philo->is_dead_mutex);
//                 pthread_mutex_unlock(&philosophe->philo->meal_mutex);
//                 return (NULL);
//             }
//             pthread_mutex_unlock(&philosophe->philo->meal_mutex);

//             if (philosophe->philo->nbr_of_times_each_philo_must_eat != -1)
//             {
//                 pthread_mutex_lock(&philosophe->philo->nb_meal_mutex);
//                 if (philosophe[i].nb_meal >= philosophe->philo->nbr_of_times_each_philo_must_eat)
//                     total_finished++;
//                 pthread_mutex_unlock(&philosophe->philo->nb_meal_mutex);
//             }
//             i++;
//         }

//         if (philosophe->philo->nbr_of_times_each_philo_must_eat != -1 
//             && total_finished == philosophe->philo->nbr_philo)
//         {
//             pthread_mutex_lock(&philosophe->philo->is_dead_mutex);
//             philosophe->philo->is_dead = 1;
//             pthread_mutex_unlock(&philosophe->philo->is_dead_mutex);
//             return (NULL);
//         }
        
//         usleep(100);
//     }
//     return (NULL);
// }

void *check_monitoring(void *arg)
{
    t_philosophe *philosophe;
    int i;
    long long current_time;
    
    philosophe = (t_philosophe *)arg;
    if (!philosophe)
        return (NULL);
    usleep(100);
    
    while (1)
    {
        i = 0;
        int total_finished = 0;
        
        while (i < philosophe->philo->nbr_philo)
        {
            pthread_mutex_lock(&philosophe->philo->meal_mutex);
            philosophe->last_meal_time = philosophe[i].last_meal_time;
            pthread_mutex_unlock(&philosophe->philo->meal_mutex);

            current_time = get_time(philosophe->philo);
            if ((current_time - philosophe->last_meal_time) >= philosophe->philo->time_to_die)
            {
                print_and_lock(&philosophe[i], "died\n");
                pthread_mutex_lock(&philosophe->philo->is_dead_mutex);
                philosophe->philo->is_dead = 1;
                pthread_mutex_unlock(&philosophe->philo->is_dead_mutex);
                return (NULL);
            }

            if (philosophe->philo->nbr_of_times_each_philo_must_eat != -1)
            {
                pthread_mutex_lock(&philosophe->philo->nb_meal_mutex);
                if (philosophe[i].nb_meal >= philosophe->philo->nbr_of_times_each_philo_must_eat)
                    total_finished++;
                pthread_mutex_unlock(&philosophe->philo->nb_meal_mutex);
            }
            i++;
        }

        pthread_mutex_lock(&philosophe->philo->is_dead_mutex);
        if (philosophe->philo->nbr_of_times_each_philo_must_eat != -1 
            && total_finished == philosophe->philo->nbr_philo)
        {
            philosophe->philo->is_dead = 1;
            pthread_mutex_unlock(&philosophe->philo->is_dead_mutex);
            return (NULL);
        }
        pthread_mutex_unlock(&philosophe->philo->is_dead_mutex);
        
        usleep(100);
    }
    return (NULL);
}
