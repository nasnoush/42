# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nadahman <nadahman@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/08 13:06:12 by nadahman          #+#    #+#              #
#    Updated: 2025/01/22 11:47:05 by nadahman         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CFLAGS = -Wall -Wextra -Werror -Iprintf -g3
CC = gcc
OBJ  = $(SRCS:.c=.o)

SRCS =	main.c \
		printf/ft_printf.c \
		printf/fonctions.c \
		printf/fonctions2.c \
		functions_moove.c \
		functions_moove2.c \
		check_error.c \
		utils.c \
		algo.c \
		functions_moove3.c \
		algo_chunks.c \
		algo_chunks2.c \
		utils2.c \
		index_utils.c \
		main2.c

norminette : 
		norminette $(SRCS)
	
all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: all clean fclean re
