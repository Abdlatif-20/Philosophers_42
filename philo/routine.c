/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.ma>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 23:08:27 by aben-nei          #+#    #+#             */
/*   Updated: 2023/06/22 20:50:55 by aben-nei         ###   ########.fr       */
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
	pthread_mutex_unlock(&philos->next->fork);
	ft_print("is sleeping\n", philos);
	ft_usleep(philos->info->time_to_sleep);
	ft_print("is thinking\n", philos);
}

void	ft_routine(t_philo *philos)
{
	if (philos->id % 2 == 0)
		usleep(100);
	while (42)
	{
		if (philos && philos->info->nb_philo == 1)
		{
			pthread_mutex_lock(&philos->fork);
			ft_print("has taken a right fork\n", philos);
			ft_usleep(philos->info->time_to_die);
		}
		else
		{
			pthread_mutex_lock(&philos->fork);
			ft_print("has taken a right fork\n", philos);
			pthread_mutex_lock(&philos->next->fork);
			ft_print("has taken a left fork\n", philos);
			ft_print("is eating\n", philos);
			ft_routine2(philos);
		}
	}
}
