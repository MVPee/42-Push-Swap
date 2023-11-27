/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvpee <mvpee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 14:06:01 by mvpee             #+#    #+#             */
/*   Updated: 2023/11/22 15:29:53 by mvpee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static long	ft_atol(const char *str)
{
	long	num;
	int		isneg;
	int		i;

	num = 0;
	isneg = 1;
	i = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
			|| str[i] == '\r' || str[i] == '\v' || str[i] == '\f'))
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		isneg *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = (num * 10) + (str[i] - '0');
		i++;
	}
	return (num * isneg);
}

static int	arg_check_isnumber(char *arg)
{
	int	i;

	i = 0;
	if (arg[i] == '-')
		i++;
	while (arg[i])
	{
		if (!ft_isdigit(arg[i]))
			return (1);
		i++;
	}
	return (0);
}

static int	arg_check_repetition(char **arg)
{
	int	i;
	int	j;

	i = 0;
	while (arg[i])
	{
		j = i + 1;
		while (arg[j])
		{
			if (ft_strcmp(arg[i], arg[j]) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	arg_check(char **arg)
{
	int		i;
	long	nb;
	int		*array;

	array = (int *)malloc(sizeof(int) * ft_splitlen((const char **)arg));
	if (!array)
		return (1);
	if (arg_check_repetition(arg))
		return (1);
	i = -1;
	while (arg[++i])
	{
		if (arg_check_isnumber(arg[i]))
			return (1);
		nb = ft_atol(arg[i]);
		if (nb > 2147483647 || nb < -2147483648)
		{
			if (array)
				free(array);
			return (1);
		}
		array[i] = nb;
	}
	return (0);
}
