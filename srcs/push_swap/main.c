/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvpee <mvpee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 13:42:15 by mvpee             #+#    #+#             */
/*   Updated: 2023/12/18 16:32:00 by mvpee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static t_stack	*find_min(t_stack *a)
{
	t_stack	*temp;
	int		min;

	temp = NULL;
	min = INT_MAX;
	while (a)
	{
		if (a->value <= min && a->rank == -1)
		{
			min = a->value;
			temp = a;
		}
		a = a->next;
	}
	return (temp);
}

static void	stack_add_rank(t_stack **a)
{
	t_stack	*stack;
	int		count;

	count = 0;
	stack = find_min(*a);
	while (stack)
	{
		stack->rank = count++;
		stack = find_min(*a);
	}
}

static void	stack_clear(t_stack **a)
{
	t_stack	*temp;

	while (*a)
	{
		temp = (*a)->next;
		free(*a);
		*a = temp;
	}
}

static void	ft_sort(t_stack **a, t_stack **b)
{
	(void)b;
	if (ft_stacksize(*a) == 2)
		sa(a);
	else if (ft_stacksize(*a) == 3)
		ft_sort_three(a);
	else if (ft_stacksize(*a) == 4)
		ft_sort_four(a, b);
	else if (ft_stacksize(*a) == 5)
		ft_sort_five(a, b);
	else
		ft_radix(a, b);
}

int	main(int ac, char **av)
{
	int		*array;
	int		len;
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (ac < 2)
		return (1);
	array = args_check(av + 1, &len);
	if (!array)
		return (ft_printf_fd(2, "Error\n"), 1);
	a = init_stack(array, len);
	if (!a)
		return (ft_free(1, &array), 1);
	ft_free(1, &array);
	stack_add_rank(&a);
	if (!is_sorted(a))
		ft_sort(&a, &b);
	stack_clear(&a);
	return (0);
}
