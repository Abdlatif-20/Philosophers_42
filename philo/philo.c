/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.ma>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 22:36:43 by aben-nei          #+#    #+#             */
/*   Updated: 2023/07/11 06:02:34 by aben-nei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_destroy(t_philo *philo, t_info *info)
{
	int	i;

	i = 0;
	while (i < info->nb_philo)
	{
		pthread_mutex_destroy(&philo->fork);
		pthread_mutex_destroy(&philo->edit_var);
		pthread_mutex_destroy(&philo->check_dead);
		pthread_mutex_destroy(&philo->must_eat_mutex);
		pthread_mutex_destroy(&philo->last_eat_mutex);
		philo = philo->next;
		i++;
	}
	pthread_mutex_destroy(&info->print_mutex);
}

int	check_is_dead(t_philo *philo)
{
	int	i;
	
	i = 0;
	if (ft_get_time() - philo->last_eat >= philo->info->time_to_die)
	{
		ft_print("\033[1;31m\033[4;31m\002\002 is dead\033[0m\n", philo);
		while (philo && i < philo->info->nb_philo)
		{
			pthread_mutex_lock(&philo->check_dead);
			philo->is_dead = true;
			pthread_mutex_unlock(&philo->check_dead);
			philo = philo->next;
			i++;
		}
		return (1);
	}
	return (0);
}

void	create_thread(t_philo *philo)
{
	int	nb_philo;

	nb_philo = philo->info->nb_philo;
	while (nb_philo)
	{
		pthread_create(&philo->thread, NULL, (void *)ft_routine, philo);
		pthread_detach(philo->thread);
		philo = philo->next;
		nb_philo--;
	}
}



int	main(int ac, char **av)
{
	t_philo	*philo;
	t_info	info;

	philo = NULL;
	if ((ac != 5 && ac != 6) || check_max_min(av, ac) || check_args(ac, av))
		return (printf(ERR_ARG), 1);
	ft_fill_info(&info, av);
	philo = fill_list(atoi(av[1]), &info);
	create_thread(philo);
	while (1)
	{
		pthread_mutex_lock(&philo->edit_var);
		if (check_is_dead(philo))
		{
			pthread_mutex_unlock(&philo->edit_var);
			return (ft_destroy(philo, &info), 1);
		}
		pthread_mutex_unlock(&philo->edit_var);
		pthread_mutex_lock(&philo->edit_var);
		if (philo->info->must_eat > 0
			&& check_if_all_eat(philo, philo->info->nb_philo, &info))
			break ;
		pthread_mutex_unlock(&philo->edit_var);
		if (philo->next)
			philo = philo->next;
	}
	return (ft_destroy(philo, &info), 0);
}
