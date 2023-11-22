# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvpee <mvpee@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/22 13:41:01 by mvpee             #+#    #+#              #
#    Updated: 2023/11/22 14:07:22 by mvpee            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

LIBFT = srcs/libft

SRCS = 	srcs/push_swap/main.c \
		srcs/push_swap/arg_check.c

OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Werror -Wextra -I$(LIBFT)
LDFLAGS = -L$(LIBFT) -lft

$(LIBFT)/libft.a:
	$(MAKE) -C $(LIBFT)

$(NAME): $(OBJS) $(LIBFT)/libft.a
	gcc $(OBJS) $(LDFLAGS) -o $(NAME)

%.o: %.c
	gcc $(CFLAGS) -c $< -o $@

all: $(NAME)

clean:
	$(MAKE) -C $(LIBFT) clean
	rm -f $(OBJS)

fclean: clean
	$(MAKE) -C $(LIBFT) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re