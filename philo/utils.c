/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 23:07:45 by aben-nei          #+#    #+#             */
/*   Updated: 2023/06/18 21:19:38 by aben-nei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	check_if_all_eat(t_philo *philo, int i, t_info *info)
{
	while (i > 0)
	{
		if (philo->num_of_eat < info->must_eat)
			return (false);
		philo = philo->next;
		i--;
	}
	return (true);
}

void	ft_print(char *str, t_philo *philo)
{
	pthread_mutex_lock(&philo->info->print_mutex);
	printf("time %ld philo %ld %s", ft_get_time() - philo->start_time,
		philo->id, str);
	pthread_mutex_unlock(&philo->info->print_mutex);
}

int	ft_usleep(long long time)
{
	long long	start;

	start = ft_get_time();
	while (ft_get_time() - start < time)
		usleep(100);
	return (1);
}

long	ft_get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}
