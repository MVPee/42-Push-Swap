/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvpee <mvpee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 10:35:53 by mvpee             #+#    #+#             */
/*   Updated: 2023/12/19 15:43:24 by mvpee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	sa(t_stack **a)
{
	t_stack	*first;
	t_stack	*second;

	if (*a != NULL && (*a)->next != NULL)
	{
		first = *a;
		second = (*a)->next;
		first->next = second->next;
		second->next = first;
		*a = second;
		ft_printf("sa\n");
	}
}

void	sb(t_stack **b)
{
	t_stack	*first;
	t_stack	*second;

	if (*b != NULL && (*b)->next != NULL)
	{
		first = *b;
		second = (*b)->next;
		first->next = second->next;
		second->next = first;
		*b = second;
		ft_printf("sb\n");
	}
}
