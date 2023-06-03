/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 22:36:43 by aben-nei          #+#    #+#             */
/*   Updated: 2023/06/03 23:06:39 by aben-nei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int ac, char **av)
{
	(void)av;
	if (check_args(ac, av) && ac != 5 && ac != 6)
	{
		printf("Error: wrong number of arguments\n");
		return (1);
	}
	return (0);
}