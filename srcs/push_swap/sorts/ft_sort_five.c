/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_five.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvpee <mvpee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 11:18:50 by mvpee             #+#    #+#             */
/*   Updated: 2023/12/15 13:44:01 by mvpee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

static void	move_smallest_to_b(t_list **a, t_list **b)
{
	int		smallest;
	int		size;
	t_list	*current;
	int		smallest_value;

	smallest = 0;
	size = 0;
	current = *a;
	smallest_value = (int)(intptr_t)(current->content);
	while (current)
	{
		if ((int)(intptr_t)(current->content) < smallest_value)
		{
			smallest_value = (int)(intptr_t)(current->content);
			smallest = size;
		}
		current = current->next;
		size++;
	}
	while (smallest > 0)
	{
		ra(a);
		smallest--;
	}
	pb(a, b);
}

static void	insert_from_b_to_a(t_list **a, t_list **b)
{
	int		value_to_insert;
	int		index_to_insert;
	t_list	*current;

	if (*b == NULL)
		return ;
	value_to_insert = (int)(intptr_t)((*b)->content);
	index_to_insert = 0;
	current = *a;
	while (current != NULL
		&& (int)(intptr_t)(current->content) < value_to_insert)
	{
		current = current->next;
		index_to_insert++;
	}
	while (index_to_insert > 0)
	{
		ra(a);
		index_to_insert--;
	}
	pa(a, b);
}

void	ft_sort_five(t_list **a, t_list **b)
{
	move_smallest_to_b(a, b);
	ft_sort_four(a, b);
	pa(a, b);
}
