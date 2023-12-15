/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvpee <mvpee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 10:35:53 by mvpee             #+#    #+#             */
/*   Updated: 2023/12/15 13:44:44 by mvpee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	sa(t_list **a)
{
	t_list	*first;
	t_list	*second;

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

void	sb(t_list **b)
{
	t_list	*first;
	t_list	*second;

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
