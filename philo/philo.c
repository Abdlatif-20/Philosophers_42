/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 22:36:43 by aben-nei          #+#    #+#             */
/*   Updated: 2023/06/05 22:51:08 by aben-nei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	fill_list(int ac, char **av, t_philo **philo)
{
	int	i;
	t_list	*list;
	int	num_philo;

	list = NULL;
	(*philo) = malloc(sizeof(t_philo));
	if (!(*philo))
		return ;
	i = 0;
	num_philo = ft_atoi(av[1]);
	while (num_philo)
	{
		while (++i < ac)
		{
			if (i == 1)
				(*philo)->id = ft_atoi(av[i]);
			else if (i == 2)
				(*philo)->time_to_die = ft_atoi(av[i]);
			else if (i == 3)
				(*philo)->time_to_eat = ft_atoi(av[i]);
			else if (i == 4)
				(*philo)->time_to_sleep = ft_atoi(av[i]);
			// else if (i == 5)
			// 	philo->is_dead = ft_atoi(av[i]);
		}
		if (!list)
			list = ft_lstnew((*philo));
		else
			ft_lstadd_back(&list, ft_lstnew((*philo)));
		num_philo--;
	}
}

int	main(int ac, char **av)
{
	t_philo	*philo;
	philo = NULL;
	if ((ac != 5 && ac != 6) || check_max_min(av, ac) || check_args(ac, av))
		return (printf("Error: wrong number of arguments\n"), 1);
	fill_list(ac, av, &philo);
	// printf("id: %lld\ntime_to_die: %lld\ntime_to_eat: %lld\ntime_to_sleep: %lld\n", philo->id, philo->time_to_die, philo->time_to_eat, philo->time_to_sleep);
	return (0);
}
