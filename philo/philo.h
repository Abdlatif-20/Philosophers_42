/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 22:36:46 by aben-nei          #+#    #+#             */
/*   Updated: 2023/06/09 22:33:49 by aben-nei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H

# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct philo_t
{
	long long		id;
	long long		time_to_die;
	long long		time_to_eat;
	long long		time_to_sleep;
	long long		start_time;
	long long		last_eat;
	long long		num_eat;
	long long		*num_of_eat;
	long long		*is_dead;
	pthread_t		thread;
	pthread_mutex_t	fork;
	pthread_mutex_t	edit_var;
	struct philo_t	*next;
}					t_philo;

// typedef struct info_t
// {
// 	long long		nb_philo;
// 	long long		time_to_die;
// 	long long		time_to_eat;
// 	long long		time_to_sleep;
// 	long long		nb_eat;
// 	long long		*is_dead;
// 	t_philo			*philo;
// 	pthread_mutex_t	*fork;
// 	pthread_mutex_t	*print;
// }					t_info;

int			check_args(int ac, char **av);
int			ft_isdigit(int c );
long long	ft_atoi(const char *str);
int			check_max_min(char **av, int ac);
long		ft_get_time(void);
t_philo		*fill_list(int len, char **av);
#endif