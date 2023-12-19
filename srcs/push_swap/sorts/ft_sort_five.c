/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_five.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvpee <mvpee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 11:18:50 by mvpee             #+#    #+#             */
/*   Updated: 2023/12/19 09:48:21 by mvpee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

static void	second_push_b(t_stack **a, t_stack **b)
{
	t_stack			*temp;
	unsigned int	count;

	temp = *a;
	count = 0;
	while (temp->rank != 1)
	{
		count++;
		temp = temp->next;
	}
	if (count > 3)
	{
		count = 5 - count;
		while (count--)
			rra(a);
	}
	else
		while (count--)
			ra(a);
	pb(a, b);
}

void	ft_sort_five(t_stack **a, t_stack **b)
{
	t_stack			*temp;
	unsigned int	count;

	temp = *a;
	count = 0;
	while (temp->rank != 0)
	{
		count++;
		temp = temp->next;
	}
	if (count > 3)
	{
		count = 5 - count;
		while (count--)
			rra(a);
	}
	else
		while (count--)
			ra(a);
	pb(a, b);
	second_push_b(a, b);
	ft_sort_three(a);
	pa(a, b);
	pa(a, b);
}
