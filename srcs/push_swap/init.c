/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvpee <mvpee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 09:38:37 by mvpee             #+#    #+#             */
/*   Updated: 2023/12/19 15:42:46 by mvpee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_stack	*init_stack(int *array, int len)
{
	t_stack	*a;
	t_stack	*new;
	int		i;

	a = NULL;
	new = NULL;
	i = 0;
	while (i < len)
	{
		new = ft_stacknew(array[i]);
		if (!new)
			return (NULL);
		ft_stackadd_back(&a, new);
		i++;
	}
	return (a);
}
