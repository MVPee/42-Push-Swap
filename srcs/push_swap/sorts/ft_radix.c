/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_radix.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvpee <mvpee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 11:19:20 by mvpee             #+#    #+#             */
/*   Updated: 2023/12/18 16:15:11 by mvpee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

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
