/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 22:36:46 by aben-nei          #+#    #+#             */
/*   Updated: 2023/06/05 22:49:08 by aben-nei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H

# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_list
{
	void			*data;
	struct s_list	*next;
}				t_list;

typedef struct philo_t
{
	long long		id;
	long long		time_to_die;
	long long		time_to_eat;
	long long		time_to_sleep;
	long long		*is_dead;
	pthread_mutex_t	fork;
	struct philo_t	*next;
	struct philo_t	*first;
}					t_philo;

int			check_args(int ac, char **av);
int			ft_isdigit(int c );
long long	ft_atoi(const char *str);
int			check_max_min(char **av, int ac);
void		ft_lstadd_back(t_list **lst, t_list *new);
t_list		*ft_lstlast(t_list *lst);
t_list		*ft_lstnew(void *data);
void		fill_list(int ac, char **av, t_philo **philo);
#endif