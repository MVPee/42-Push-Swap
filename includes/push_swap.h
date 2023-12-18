/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvpee <mvpee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 13:39:59 by mvpee             #+#    #+#             */
/*   Updated: 2023/12/18 16:06:23 by mvpee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../srcs/libft/includes/libft.h"

typedef struct s_stack
{
	int				value;
	int				rank;
	struct s_stack	*next;
}					t_stack;

/* Handle input error */
int					*args_check(char **av, int *len);

/* Init_stack_a with an array of int */
t_stack				*init_stack(int *array, int len);

/* Stacks utils */
int					ft_stacksize(t_stack *lst);
t_stack				*ft_stacknew(int value);
t_stack				*ft_stacklast(t_stack *lst);
void				ft_stackadd_back(t_stack **lst, t_stack *new);
int					is_sorted(t_stack *a);

/* Sorts methode */
void				ft_sort_three(t_stack **a);
void				ft_sort_four(t_stack **a, t_stack **b);
void				ft_sort_five(t_stack **a, t_stack **b);
void				ft_radix(t_stack **stack_a, t_stack **stack_b);

/* Operations methode */
// Swap
void				sa(t_stack **a);
void				sb(t_stack **b);
// Rotate
void				ra(t_stack **a);
void				rra(t_stack **a);
// Push
void				pa(t_stack **a, t_stack **b);
void				pb(t_stack **a, t_stack **b);

#endif