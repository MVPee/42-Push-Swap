/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-pee <mvan-pee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 11:18:50 by mvpee             #+#    #+#             */
/*   Updated: 2023/12/20 10:30:05 by mvan-pee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_radix(t_stack **a, t_stack **b)
{
	int	i;
	int	j;
	int	size;

	size = ft_stacksize(*a);
	i = 0;
	while (!is_sorted(*a))
	{
		j = 0;
		while (j < size)
		{
			if ((((*a)->rank >> i) & 1) == 0)
				pb(a, b);
			else
				ra(a);
			j++;
		}
		while (ft_stacksize(*b) > 0)
			pa(a, b);
		i++;
	}
}

void	ft_sort_three(t_stack **a)
{
	int	top;
	int	middle;
	int	bottom;

	top = (*a)->value;
	middle = (*a)->next->value;
	bottom = (*a)->next->next->value;
	if (top > middle && middle < bottom && top < bottom)
		sa(a);
	else if (top > middle && middle > bottom)
	{
		sa(a);
		rra(a);
	}
	else if (top > middle && middle < bottom && top > bottom)
		ra(a);
	else if (top < middle && middle > bottom && top < bottom)
	{
		sa(a);
		ra(a);
	}
	else if (top < middle && middle > bottom && top > bottom)
		rra(a);
}

static void	ft_push_to_b(t_stack **a, t_stack **b)
{
	t_stack	*temp;
	int		i;
	int		pos;

	i = 0;
	while (ft_stacksize(*a) > 3)
	{
		temp = *a;
		pos = 0;
		while (temp && temp->rank != i)
		{
			pos++;
			temp = temp->next;
		}
		if ((*a)->rank == i)
		{
			pb(a, b);
			i++;
		}
		else if (pos <= ft_stacksize(*a) / 2)
			ra(a);
		else
			rra(a);
	}
}

void	ft_sort(t_stack **a, t_stack **b)
{
	ft_push_to_b(a, b);
	ft_sort_three(a);
	while (ft_stacksize(*b) != 0)
		pa(a, b);
}
