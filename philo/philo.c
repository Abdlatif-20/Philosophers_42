/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 22:36:43 by aben-nei          #+#    #+#             */
/*   Updated: 2023/06/20 02:15:37 by aben-nei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_is_dead(t_philo *philo)
{
	int	i;

	i = 0;
	pthread_mutex_lock(philo->info->mut_dead);
	int	check_time = ft_get_time() - philo->last_eat;
	pthread_mutex_unlock(philo->info->mut_dead);
	if (check_time >= philo->info->time_to_die)
	{
			pthread_mutex_lock(&philo->variable);
		while (i <= philo->info->nb_philo)
		{
		// pthread_mutex_lock(philo->info->mut_dead);
			philo->is_dead = 1;
		// pthread_mutex_unlock(philo->info->mut_dead);
			if(philo->next)
				philo = philo->next;
			i++;
			pthread_mutex_unlock(&philo->variable);
		}
		pthread_mutex_lock(philo->info->mut_dead);
		ft_print("is dead\n", philo);
		pthread_mutex_unlock(philo->info->mut_dead);
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

int	main(int ac, char **av)
{
	t_philo	*philo;
	t_info	info;

	philo = NULL;
	if ((ac != 5 && ac != 6) || check_max_min(av, ac) || check_args(ac, av))
		return (printf("Error: wrong number of arguments\n"), 1);
	ft_fill_info(&info, av);
	philo = fill_list(atoi(av[1]), &info);
	create_thread(philo);
	while (1)
	{
		if (check_is_dead(philo))
			break ;

		pthread_mutex_lock(&info.edit_var);
		if (philo->info->must_eat > 0
			&& check_if_all_eat(philo, philo->info->nb_philo, &info))
			break ;
		pthread_mutex_unlock(&info.edit_var);
		if (philo->next)
			philo = philo->next;
	}
	return (0);
}
