/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.ma>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 01:22:35 by aben-nei          #+#    #+#             */
/*   Updated: 2023/07/25 19:21:17 by aben-nei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_isdigit(int c )
{
	if ((c >= '0' && c <= '9'))
		return (1);
	return (0);
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	check_args(int ac, char **av)
{
	int	i;
	int	j;
	int	flag;

	i = 1;
	flag = 0;
	while (i < ac)
	{
		j = 0;
		if (!av[i][j])
			return (1);
		while (av[i][j])
		{
			if (av[i][j] == '+')
				flag++;
			else if (!ft_isdigit(av[i][j]) || av[i][ft_strlen(av[i]) - 1] == '+')
				return (1);
			if (flag > 1)
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
		if (nb > 2147483647 || nb < 0)
			return (1);
	}
	return (0);
}
