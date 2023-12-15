/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_three.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvpee <mvpee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 11:18:13 by mvpee             #+#    #+#             */
/*   Updated: 2023/12/15 11:23:42 by mvpee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

void	ft_sort_three(t_list **a)
{
	int	top;
	int	middle;
	int	bottom;

	top = (int)(intptr_t)(*a)->content;
	middle = (int)(intptr_t)(*a)->next->content;
	bottom = (int)(intptr_t)(*a)->next->next->content;
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
