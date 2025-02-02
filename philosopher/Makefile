# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nas <nas@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/30 10:52:17 by nas               #+#    #+#              #
#    Updated: 2025/01/31 11:32:36 by nas              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
CFLAGS = -Wall -Wextra -Werror -g3
CC = gcc -pthread
OBJ  = $(SRCS:.c=.o)

SRCS =	philo.c \
		utils.c \
		main.c \

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
