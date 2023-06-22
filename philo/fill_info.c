/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 21:06:20 by aben-nei          #+#    #+#             */
/*   Updated: 2023/06/20 02:13:37 by aben-nei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_fill_info(t_info *info, char **av)
{
	info->nb_philo = ft_atoi(av[1]);
	info->time_to_die = ft_atoi(av[2]);
	info->time_to_eat = ft_atoi(av[3]);
	info->time_to_sleep = ft_atoi(av[4]);
	if (av[5])
		info->must_eat = ft_atoi(av[5]);
	else
		info->must_eat = -1;
	pthread_mutex_init(&info->edit_var, NULL);
	pthread_mutex_init(&info->print_mutex, NULL);
	info->mut_dead = malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(info->mut_dead, NULL);
}
