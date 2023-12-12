/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvpee <mvpee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 13:42:15 by mvpee             #+#    #+#             */
/*   Updated: 2023/12/12 20:17:49 by mvpee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int is_sorted(int *array)
{
	int temp;
	int i;

	temp = array[0];
	i = 1;
	while(array[i])
	{
		if (temp > array[i])
			return (0);
		temp = array[i];
		i++;
	}
	return (1);
}

int	main(int ac, char **av)
{
	char			**arg;
	int				*array;

	if (ac < 2 || !av[1][0])
		return (ft_printf_fd(2, "Error\n"));
	if (ac == 2)
	{
		arg = ft_split(av[1], " ");
		if (!arg)
			return (1);
	}
	else
		arg = av + 1;
	array = arg_check(arg);
	if (!array)
	{
		ft_free_split(1, &arg);
		return (ft_printf_fd(2, "Error\n"));
	}
	if (!is_sorted(array))
	{
		if(ft_intlen(array) == 2)
			ft_printf("sa\n");
		else if(ft_intlen(array) == 3)
			ft_printf("3\n");
		else
			ft_printf("MORE\n");
	}
	return (0);
}
