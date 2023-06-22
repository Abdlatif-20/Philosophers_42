/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 23:08:27 by aben-nei          #+#    #+#             */
/*   Updated: 2023/06/20 02:16:19 by aben-nei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_routine2(t_philo *philos)
{
	pthread_mutex_lock(&philos->info->edit_var);
	philos->last_eat = ft_get_time();
	philos->num_of_eat++;
	pthread_mutex_unlock(&philos->info->edit_var);
	ft_usleep(philos->info->time_to_eat);
	pthread_mutex_unlock(&philos->fork);
	if(philos->next)
	pthread_mutex_unlock(&philos->next->fork);
	if (!philos->is_dead)
	{
	pthread_mutex_lock(philos->info->mut_dead);
		ft_print("is sleeping\n", philos);
	pthread_mutex_unlock(philos->info->mut_dead);
	}
	ft_usleep(philos->info->time_to_sleep);
	// pthread_mutex_lock(philos->info->mut_dead);
	if (!philos->is_dead)
		ft_print("is thinking\n", philos);
	// pthread_mutex_unlock(philos->info->mut_dead);
}

void	ft_routine(t_philo *philos)
{
	if (philos->id % 2 == 0)
		usleep(100);
	while (42)
	{
		pthread_mutex_lock(&philos->fork);
		// pthread_mutex_lock(philos->info->mut_dead);
   		if (!philos->is_dead)
			ft_print("has taken a right fork\n", philos);
		// pthread_mutex_unlock(philos->info->mut_dead);
		if(philos->next && !philos->is_dead)
		{
			pthread_mutex_lock(&philos->next->fork);
		pthread_mutex_lock(philos->info->mut_dead);
			if (!philos->is_dead)
				ft_print("has taken a left fork\n", philos);
		pthread_mutex_unlock(philos->info->mut_dead);
		pthread_mutex_lock(philos->info->mut_dead);
			if (!philos->is_dead)
				ft_print("is eating\n", philos);
		pthread_mutex_unlock(philos->info->mut_dead);
			ft_routine2(philos);
		}
	}
}
