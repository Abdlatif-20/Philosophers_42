/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 22:36:43 by aben-nei          #+#    #+#             */
/*   Updated: 2023/06/09 21:26:45 by aben-nei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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

void	ft_routine(t_philo *philos)
{
	if (philos->id % 2 == 0)
		usleep(100);
	while (42)
	{
		pthread_mutex_lock(&philos->fork);
		printf("time %lld philo %lld has taken a right fork\n",
			ft_get_time() - philos->start_time, philos->id);
		pthread_mutex_lock(&philos->next->fork);
		printf("time %lld philo %lld has taken a left fork\n",
			ft_get_time() - philos->start_time, philos->id);
		printf("time %lld philo %lld is eating\n",
			ft_get_time() - philos->start_time, philos->id);
		philos->last_eat = ft_get_time();
		ft_usleep(philos->time_to_eat);
		pthread_mutex_unlock(&philos->fork);
		pthread_mutex_unlock(&philos->next->fork);
		printf("time %lld philo %lld is sleeping\n",
			ft_get_time() - philos->start_time, philos->id);
		ft_usleep(philos->time_to_sleep);
		printf("time %lld philo %lld is thinking\n",
			ft_get_time() - philos->start_time, philos->id);
	}
}

int	main(int ac, char **av)
{
	t_philo	*philo;
	t_philo	*head;
	int		len;

	philo = NULL;
	if ((ac != 5 && ac != 6) || check_max_min(av, ac) || check_args(ac, av))
		return (printf("Error: wrong number of arguments\n"), 1);
	philo = fill_list(atoi(av[1]), av);
	head = philo;
	len = atoi(av[1]);
	// while (len > 0)
	// {
	// 	printf("id: %lld\n", philo->id);
	// 	printf("time_to_die: %lld\n", philo->time_to_die);
	// 	printf("time_to_eat: %lld\n", philo->time_to_eat);
	// 	printf("time_to_sleep: %lld\n", philo->time_to_sleep);
	// 	printf("-------------------\n");
	// 	philo = philo->next;
	// 	len--;
	// }
	while (len > 0)
	{
		pthread_create(&philo->thread, NULL, (void *)ft_routine, philo);
		philo = philo->next;
		len--;
	}
	philo = head;
	while (1) /*check death and the optional argument*/
	{
		if (ft_get_time() - philo->last_eat > philo->time_to_die)
		{
			printf("time %lld philo %lld is dead\n",
				ft_get_time() - philo->start_time, philo->id);
			return (0);
		}
		philo = philo->next;
	}
	return (0);
}
/*

routine

pthread_mutex_lock(fork)
print philo khda fork
pthread_mutex_lock(t->next->fork)
print philo khda fork
print(bda yakl)
usleep (t_to eat)
unlock(fork)
unlock(fork->next)
print(sleap)
usleep ()
print(tinking)

*/
