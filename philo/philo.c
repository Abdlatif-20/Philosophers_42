/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 22:36:43 by aben-nei          #+#    #+#             */
/*   Updated: 2023/06/06 23:10:51 by aben-nei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo *ft_creat_philo(char **av, int i)
{
	t_philo *head;

	head = malloc(sizeof(t_philo));
	head->id = i;
	head->time_to_die = ft_atoi(av[2]);
	head->time_to_eat = ft_atoi(av[3]);
	head->time_to_sleep = ft_atoi(av[4]);
	pthread_mutex_init(&head->fork, NULL);
	head->next = NULL;
	return(head);
}

t_philo *fill_list(int ac, char **av)
{
	int	i = 0;
	t_philo	*list;
	t_philo	*head;

	list = ft_creat_philo(av, ++i);
	head = list;
	while (ac > i)
	{
		list->next = ft_creat_philo(av, ++i);
		list = list->next;
	}
	list = head;
	return (head);
}

int	main(int ac, char **av)
{
	t_philo	*philo;

	// int len = atoi(av[1]);
	philo = NULL;
	if ((ac != 5 && ac != 6) || check_max_min(av, ac) || check_args(ac, av))
		return (printf("Error: wrong number of arguments\n"), 1);
	philo = fill_list(ac, av);
	// while (len > 0)
	// {
	// 	printf("id: %lld\ntime_to_die: %lld\ntime_to_eat: %lld\ntime_to_sleep: %lld\n", philo->id, philo->time_to_die, philo->time_to_eat, philo->time_to_sleep);
	// 	printf("-------------------\n");
	// 	philo = philo->next;
	// 	len--;
	// }
	return (0);
}
