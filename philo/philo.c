/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 22:36:43 by aben-nei          #+#    #+#             */
/*   Updated: 2023/06/04 18:13:29 by aben-nei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	if ((ac != 5 && ac != 6) || check_max_min(av, ac) || check_args(ac, av))
		return (printf("Error: wrong number of arguments\n"), 1);
	return (0);
}
