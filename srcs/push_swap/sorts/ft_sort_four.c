/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_four.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvpee <mvpee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 11:19:22 by mvpee             #+#    #+#             */
/*   Updated: 2023/12/15 13:44:09 by mvpee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

static int	find_index_of_smallest(t_list *a)
{
	int		index;
	int		smallest_index;
	int		smallest_value;
	t_list	*current;

	index = 0;
	smallest_index = 0;
	if (!a)
		return (-1);
	smallest_value = (int)(intptr_t)(a->content);
	current = a;
	while (current)
	{
		if ((int)(intptr_t)(current->content) < smallest_value)
		{
			smallest_value = (int)(intptr_t)(current->content);
			smallest_index = index;
		}
		index++;
		current = current->next;
	}
	return (smallest_index);
}

static void	move_to_top(t_list **a, int index)
{
	int	stack_size;

	stack_size = ft_lstsize(*a);
	if (index < stack_size / 2)
	{
		while (index--)
			ra(a);
	}
	else
	{
		index = stack_size - index;
		while (index--)
			rra(a);
	}
}

void	ft_sort_four(t_list **a, t_list **b)
{
	int	smallest;

	smallest = find_index_of_smallest(*a);
	move_to_top(a, smallest);
	pb(a, b);
	ft_sort_three(a);
	pa(a, b);
}
