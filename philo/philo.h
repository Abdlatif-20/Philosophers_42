/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 22:36:46 by aben-nei          #+#    #+#             */
/*   Updated: 2023/06/20 02:12:18 by aben-nei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H

# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdbool.h>

typedef struct info_t
{
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	long			nb_philo;
	long			must_eat;
	pthread_mutex_t	edit_var;
	pthread_mutex_t	*mut_dead;
	pthread_mutex_t	print_mutex;
}					t_info;

typedef struct philo_t
{
	long			id;
	long			start_time;
	long			last_eat;
	long			num_of_eat;
	int				is_dead;
	pthread_t		thread;
	pthread_mutex_t	variable;
	pthread_mutex_t	fork;
	t_info			*info;
	struct philo_t	*next;
}					t_philo;

int			check_args(int ac, char **av);
int			ft_isdigit(int c );
long long	ft_atoi(const char *str);
int			check_max_min(char **av, int ac);
long		ft_get_time(void);
t_philo		*fill_list(int len, t_info *info);
void		ft_fill_info(t_info *info, char **av);
void		ft_routine(t_philo *philos);
bool		check_if_all_eat(t_philo *philo, int i, t_info *info);
void		ft_print(char *str, t_philo *philo);
int			ft_usleep(long long time);
long		ft_get_time(void);
#endif