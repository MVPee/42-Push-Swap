# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvan-pee <mvan-pee@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/22 13:41:01 by mvpee             #+#    #+#              #
#    Updated: 2023/12/20 10:29:55 by mvan-pee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

LIBFT = srcs/libft

SRCS = 	srcs/push_swap/main.c \
		srcs/push_swap/arg_check.c \
		srcs/push_swap/init.c \
		srcs/push_swap/ft_sort.c \
		srcs/push_swap/operations/swap.c \
		srcs/push_swap/operations/rotate.c \
		srcs/push_swap/operations/push.c \
		srcs/push_swap/stacks/stacks_utils.c \

OBJS = $(SRCS:.c=.o)

CFLAGS = -I$(LIBFT) -Wall -Werror -Wextra
LDFLAGS = -L$(LIBFT) -lft

all: $(NAME)

$(LIBFT)/libft.a:
	$(MAKE) -C $(LIBFT)

$(NAME): $(OBJS) $(LIBFT)/libft.a
	gcc $(OBJS) $(LDFLAGS) -o $(NAME)

%.o: %.c
	gcc $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) -C $(LIBFT) clean
	rm -f $(OBJS)

fclean: clean
	$(MAKE) -C $(LIBFT) fclean
	rm -f $(NAME)

re: fclean all

sort: all
	./push_swap 1 4 56 1009 12938

nsort: all
	./push_swap 1 2 56 12938 1009 

.PHONY: all clean fclean re