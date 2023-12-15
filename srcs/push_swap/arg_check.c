/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvpee <mvpee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 14:06:01 by mvpee             #+#    #+#             */
/*   Updated: 2023/12/15 13:11:12 by mvpee            ###   ########.fr       */
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

static int	args_check_isnumber(char *args)
{
	int	i;

	i = 0;
	if (args[i] == '-')
		i++;
	while (args[i])
	{
		if (!ft_isdigit(args[i]))
			return (1);
		i++;
	}
	return (0);
}

static int	args_check_repetition(char **args)
{
	int	i;
	int	j;

	i = 0;
	while (args[i])
	{
		j = i + 1;
		while (args[j])
		{
			if (ft_strcmp(args[i], args[j]) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static char	**create_args(char **av)
{
	char	*str;
	char	*temp;
	char	**args;
	int		i;

	str = ft_strdup(av[0]);
	if (!str)
		return (NULL);
	i = 0;
	while (av[++i])
	{
		temp = ft_strjoin(str, " ");
		if (!temp)
			return (ft_free(1, &str), NULL);
		ft_free(1, &str);
		str = temp;
		temp = ft_strjoin(str, av[i]);
		if (!temp)
			return (ft_free(1, &str), NULL);
		ft_free(1, &str);
		str = temp;
	}
	args = ft_split(str, " ");
	return (ft_free(1, &str), args);
}

int	*args_check(char **av, int *len)
{
	long	nb;
	int		*array;
	char	**args;

	args = create_args(av);
	if (!args)
		return (NULL);
	array = (int *)malloc(sizeof(int) * ft_splitlen((const char **)args));
	if (!array)
		return NULL;
	if (args_check_repetition(args))
		return (ft_free(1, &array), ft_free_matrix(1, &args), NULL);
	*len = -1;
	while (args[++(*len)])
	{
		if (args_check_isnumber(args[*len]))
			return (ft_free(1, &array), ft_free_matrix(1, &args), NULL);
		nb = ft_atol(args[*len]);
		if (nb > 2147483647 || nb < -2147483648)
		{
			return (ft_free(1, &array), NULL);
		}
		array[*len] = nb;
	}
	return (ft_free_matrix(1, &args), array);
}
