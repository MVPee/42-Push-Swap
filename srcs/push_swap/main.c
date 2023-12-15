/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvpee <mvpee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 13:42:15 by mvpee             #+#    #+#             */
/*   Updated: 2023/12/15 12:07:40 by mvpee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	is_sorted(t_list *a)
{
	while (a->next != NULL)
	{
		if (a->content > a->next->content)
			return (0);
		a = a->next;
	}
	return (1);
}

static void	ft_sort(t_list **a, t_list **b)
{
	(void)b;
	if (ft_lstsize(*a) == 1)
		return ;
	else if (ft_lstsize(*a) == 2)
		sa(a);
	else if (ft_lstsize(*a) == 3)
		ft_sort_three(a);
	else if (ft_lstsize(*a) == 4)
		ft_sort_four(a);
	else if (ft_lstsize(*a) == 5)
		ft_sort_five(a, b);
	// else
	// 	ft_big_sort(a, b);
}

int	main(int ac, char **av)
{
	int		*array;
	int		len;
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;
	if (ac < 2)
		return (1);
	array = args_check(av + 1, &len);
	if (!array)
		return (ft_printf_fd(2, "Error\n"));
	a = init_stack(array, len);
	ft_free(1, &array);
	if (!is_sorted(a))
		ft_sort(&a, &b);
	return (0);
}
