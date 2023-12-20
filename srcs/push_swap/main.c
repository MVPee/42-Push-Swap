/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-pee <mvan-pee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 13:42:15 by mvpee             #+#    #+#             */
/*   Updated: 2023/12/20 10:36:09 by mvan-pee         ###   ########.fr       */
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

static void	sort(t_stack **a, t_stack **b)
{
	if (ft_stacksize(*a) == 2)
		sa(a);
	else if (ft_stacksize(*a) == 3)
		ft_sort_three(a);
	else if (ft_stacksize(*a) <= 5)
		ft_sort(a, b);
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
		return (0);
	array = args_check(av + 1, &len);
	if (!array)
		return (ft_printf_fd(2, "Error\n"), 0);
	a = init_stack(array, len);
	if (!a)
		return (stack_clear(&a), ft_free(1, &array), 1);
	ft_free(1, &array);
	stack_add_rank(&a);
	if (!is_sorted(a))
		sort(&a, &b);
	stack_clear(&a);
	return (0);
}
