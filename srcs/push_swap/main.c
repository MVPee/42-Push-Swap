/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvpee <mvpee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 13:42:15 by mvpee             #+#    #+#             */
/*   Updated: 2023/11/22 15:26:47 by mvpee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	main(int ac, char **av)
{
	t_stack_node	*a;
	char			**arg;

	a = NULL;
	(void)a;
	if (ac < 2 || !av[1][0])
		return (ft_printf_fd(2, "Error\n"));
	if (ac == 2)
		arg = ft_split(av[1], ' ');
	else
		arg = av + 1;
	if (arg_check(arg))
	{
		ft_free_split(arg);
		return (ft_printf_fd(2, "Error\n"));
	}
	return (0);
}
