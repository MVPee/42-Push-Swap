/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvpee <mvpee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 10:42:26 by mvpee             #+#    #+#             */
/*   Updated: 2023/12/19 15:43:58 by mvpee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

void	ra(t_stack **a)
{
	t_stack	*first;
	t_stack	*last;

	if (*a == NULL || (*a)->next == NULL)
		return ;
	first = *a;
	last = ft_stacklast(*a);
	*a = first->next;
	first->next = NULL;
	last->next = first;
	ft_printf("ra\n");
}

void	rb(t_stack **b)
{
	t_stack	*first;
	t_stack	*last;

	if (*b == NULL || (*b)->next == NULL)
		return ;
	first = *b;
	last = ft_stacklast(*b);
	*b = first->next;
	first->next = NULL;
	last->next = first;
	ft_printf("ra\n");
}

void	rra(t_stack **a)
{
	t_stack	*last;
	t_stack	*second_last;

	if (*a == NULL || (*a)->next == NULL)
		return ;
	last = *a;
	second_last = NULL;
	while (last->next != NULL)
	{
		second_last = last;
		last = last->next;
	}
	if (second_last != NULL)
	{
		second_last->next = NULL;
		last->next = *a;
		*a = last;
	}
	ft_printf("rra\n");
}
