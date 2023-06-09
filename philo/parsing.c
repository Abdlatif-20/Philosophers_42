/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 01:22:35 by aben-nei          #+#    #+#             */
/*   Updated: 2023/06/08 01:22:37 by aben-nei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_isdigit(int c )
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	check_args(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			if (!ft_isdigit(av[i][j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

long long	ft_atoi(const char *str)
{
	long long		res;
	long long		sign;

	if (!str)
		return (0);
	res = 0;
	sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		res = (res * 10) + (*str - '0');
		str++;
	}
	return (sign * res);
}

int	check_max_min(char **av, int ac)
{
	long long	nb;
	int			i;

	i = 0;
	while (++i < ac)
	{
		nb = ft_atoi(av[i]);
		if (nb > 2147483647 || nb < 0 || nb == 0)
			return (1);
	}
	return (0);
}
