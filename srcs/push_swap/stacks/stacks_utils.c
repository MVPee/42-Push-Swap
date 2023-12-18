/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvpee <mvpee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 15:05:07 by mvpee             #+#    #+#             */
/*   Updated: 2023/12/18 16:06:29 by mvpee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

int	ft_stacksize(t_stack *lst)
{
	int		len;
	t_stack	*temp;

	temp = lst;
	if (!temp)
		return (0);
	len = 0;
	while (temp)
	{
		temp = temp->next;
		len++;
	}
	return (len);
}

t_stack	*ft_stacknew(int value)
{
	t_stack	*list;

	list = malloc(sizeof(t_stack));
	if (!(list))
		return (NULL);
	list->value = value;
	list->rank = -1;
	list->next = NULL;
	return (list);
}

t_stack	*ft_stacklast(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_stackadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*last;

	if (!new || !lst)
		return ;
	if (!*lst)
		*lst = new;
	else
	{
		last = ft_stacklast(*lst);
		last->next = new;
	}
}

int	is_sorted(t_stack *a)
{
	while (a->next != NULL)
	{
		if (a->value > a->next->value)
			return (0);
		a = a->next;
	}
	return (1);
}
