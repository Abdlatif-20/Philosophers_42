/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 22:36:46 by aben-nei          #+#    #+#             */
/*   Updated: 2023/06/04 17:26:51 by aben-nei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H

# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

// typedef struct philo_t;
// {
// }				t_philo;

int			check_args(int ac, char **av);
int			ft_isdigit(int c );
long long	ft_atoi(const char *str);
int			check_max_min(char **av, int ac);

#endif