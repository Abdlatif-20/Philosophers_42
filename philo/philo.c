/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.ma>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 22:36:43 by aben-nei          #+#    #+#             */
/*   Updated: 2023/06/22 21:35:28 by aben-nei         ###   ########.fr       */
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
			philo = philo->next;
		i++;
	}
	pthread_mutex_destroy(&info->edit_var);
	pthread_mutex_destroy(&info->mut_dead);
	pthread_mutex_destroy(&info->print_mutex);
	free(philo);
}

int	check_is_dead(t_philo *philo)
{
	int	i;

	i = 0;
	if (ft_get_time() - philo->last_eat >= philo->info->time_to_die)
	{
		ft_print("\033[1;31m\033[4;31m\002\002 is dead\033[0m\n", philo);
		pthread_mutex_lock(&philo->info->mut_dead);
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
		philo = philo->next;
		nb_philo--;
	}
}
void	ff()
{
	system("leaks philo");
}

int	main(int ac, char **av)
{
	t_philo	*philo;
	t_info	info;

	// atexit(ff);
	philo = NULL;
	if ((ac != 5 && ac != 6) || check_max_min(av, ac) || check_args(ac, av))
		return (printf(ERR_ARG), 1);
	ft_fill_info(&info, av);
	philo = fill_list(atoi(av[1]), &info);
	create_thread(philo);
	while (1)
	{
		pthread_mutex_lock(&info.edit_var);
		if (check_is_dead(philo))
		{
			ft_destroy(philo, &info);
			break ;
		}
		pthread_mutex_unlock(&info.edit_var);
		pthread_mutex_lock(&info.edit_var);
		if (philo->info->must_eat > 0
			&& check_if_all_eat(philo, philo->info->nb_philo, &info))
		{
			ft_destroy(philo, &info);
			break ;
		}
		pthread_mutex_unlock(&info.edit_var);
		if (philo->next)
			philo = philo->next;
	}
	return (0);
}
