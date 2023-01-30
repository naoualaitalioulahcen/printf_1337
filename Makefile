# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nait-ali <nait-ali@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/19 22:21:21 by nait-ali          #+#    #+#              #
#    Updated: 2022/11/14 15:05:59 by nait-ali         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc 

CFLAGS = -Wall -Wextra -Werror

ARC = ar rc

FILES = ft_printf.c ft_printf_fnc.c

OBJS = $(FILES:.c=.o)

all:$(NAME)

$(NAME): $(OBJS)
	$(ARC) $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

%.o : %.c ft_printf.h
	$(CC) $(CFLAGS) -o $@ -c $<

fclean: clean
	rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re