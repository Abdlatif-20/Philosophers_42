/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 01:21:28 by aben-nei          #+#    #+#             */
/*   Updated: 2023/06/09 21:18:00 by aben-nei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	*ft_creat_philo(char **av, int i, t_philo *head)
{
	t_philo	*philo;

	philo = malloc(sizeof(t_philo));
	philo->id = i;
	philo->time_to_die = ft_atoi(av[2]);
	philo->time_to_eat = ft_atoi(av[3]);
	philo->time_to_sleep = ft_atoi(av[4]);
	philo->start_time = ft_get_time();
	philo->last_eat = ft_get_time();
	pthread_mutex_init(&philo->fork, NULL);
	philo->next = head;
	return (philo);
}

t_philo	*fill_list(int len, char **av)
{
	int		i;
	t_philo	*list;
	t_philo	*head;

	i = 0;
	head = NULL;
	list = ft_creat_philo(av, ++i, head);
	head = list;
	while (len > i)
	{
		list->next = ft_creat_philo(av, ++i, head);
		list = list->next;
	}
	list = head;
	return (head);
}
