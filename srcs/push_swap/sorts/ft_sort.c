/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvpee <mvpee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 11:18:50 by mvpee             #+#    #+#             */
/*   Updated: 2023/12/19 15:40:47 by mvpee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

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
