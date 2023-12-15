/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvpee <mvpee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 09:38:37 by mvpee             #+#    #+#             */
/*   Updated: 2023/12/15 13:19:19 by mvpee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_list	*init_stack(int *array, int len)
{
	t_list *a = NULL;
	t_list *new = NULL;
	int i;

	i = 0;
	while (i < len)
	{
		new = ft_lstnew((void *)(intptr_t)array[i]);
		if (!new)
		{
			ft_lstclear(&a, free);
			return (NULL);
		}
		ft_lstadd_back(&a, new);
		i++;
	}
	return (a);
}