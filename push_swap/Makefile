# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nadahman <nadahman@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/08 13:06:12 by nadahman          #+#    #+#              #
#    Updated: 2025/01/09 11:40:26 by nadahman         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CFLAGS = -Wall -Wextra -Werror
CC = gcc

SRCS = printf/ft_printf.c printf/fonctions.c printf/fonctions2.c functions_moove.c main.c

all: $(NAME)

clean:
    rm -f $(SRCS)
    
re: fclean all

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@