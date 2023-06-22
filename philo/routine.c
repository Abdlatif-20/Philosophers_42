/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.ma>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 23:08:27 by aben-nei          #+#    #+#             */
/*   Updated: 2023/06/22 21:31:46 by aben-nei         ###   ########.fr       */
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
	ft_print("\033[4;33m\002is sleeping\033[0m\n", philos);
	ft_usleep(philos->info->time_to_sleep);
	ft_print("\033[0;34mis thinking\033[0m\n", philos);
}

void	ft_routine(t_philo *philos)
{
	if (philos->id % 2 == 0)
		usleep(100);
	while (42)
	{
		pthread_mutex_lock(&philos->fork);
		ft_print("\033[4;32m\002has taken a right fork\033[0m\n", philos);
		if (philos->next)
		{
			pthread_mutex_lock(&philos->next->fork);
			ft_print("\033[4;32m\002has taken a left fork\033[0m\n", philos);
			ft_print("\033[0;35mis eating\033[0m\n", philos);
			ft_routine2(philos);
		}
	}
}
