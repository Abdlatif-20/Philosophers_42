/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 01:21:28 by aben-nei          #+#    #+#             */
/*   Updated: 2023/06/18 18:32:20 by aben-nei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	*ft_creat_philo(int i, t_philo *head, t_info *info)
{
	t_philo	*philo;

	philo = malloc(sizeof(t_philo));
	if (!philo)
		return (NULL);
	philo->info = info;
	philo->id = i;
	philo->start_time = ft_get_time();
	philo->last_eat = ft_get_time();
	philo->num_of_eat = 0;
	philo->is_dead = 0;
	pthread_mutex_init(&philo->fork, NULL);
	philo->next = head;
	return (philo);
}

t_philo	*fill_list(int len, t_info *info)
{
	int		i;
	t_philo	*list;
	t_philo	*head;

	i = 0;
	head = NULL;
	list = ft_creat_philo(++i, head, info);
	head = list;
	while (len > i)
	{
		list->next = ft_creat_philo(++i, head, info);
		list = list->next;
	}
	list = head;
	return (head);
}
