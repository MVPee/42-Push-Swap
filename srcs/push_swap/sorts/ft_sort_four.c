/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_four.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvpee <mvpee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 11:19:22 by mvpee             #+#    #+#             */
/*   Updated: 2023/12/19 09:16:52 by mvpee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

void	ft_sort_four(t_stack **a, t_stack **b)
{
	t_stack *temp;
	unsigned int count;
	
	temp = *a;
	count = 0;
	while(temp->rank != 0)
	{
		count++;
		temp = temp->next;
	}
	while(count--)
		ra(a);
	pb(a, b);
	ft_sort_three(a);
	pa(a, b);
}
