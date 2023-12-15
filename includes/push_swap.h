/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvpee <mvpee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 13:39:59 by mvpee             #+#    #+#             */
/*   Updated: 2023/12/15 14:08:19 by mvpee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../srcs/libft/includes/libft.h"

typedef struct s_node
{
	int					value;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}						t_node;

/* Handle input error */
int						*args_check(char **av, int *len);

/* Init_stack_a with an array of int */
t_list					*init_stack(int *array, int len);

/* Sorts methode */
void					ft_sort_three(t_list **a);
void					ft_sort_four(t_list **a, t_list **b);
void					ft_sort_five(t_list **a, t_list **b);
void					radix_sort(t_list **stack_a, t_list **stack_b);

/* Operations methode */
// Swap
void					sa(t_list **a);
void					sb(t_list **b);
// Rotate
void					ra(t_list **a);
void					rra(t_list **a);
// Push
void					pa(t_list **a, t_list **b);
void					pb(t_list **a, t_list **b);

#endif