# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nadahman <nadahman@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/11 12:21:30 by nadahman          #+#    #+#              #
#    Updated: 2024/11/12 14:10:02 by nadahman         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= so_long
CFLAGS	= -Wall -Wextra -Werror -I./mlx -I.GNL
CC		= gcc
MLX 	= -lmlx -framework OpenGL -framework AppKit
OBJ 	= $(SRCS:.c=.o)

#FICHIERS SOURCES
SRCS	= 	main.c GNL/get_next_line.c

#REGLES
all: $(NAME)

#COMPILATION DE LA BIBLIOTHEQUE
$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

#COMPILATION DES FICHIERS .c EN .o
%.o: %.c 
	$(CC) $(CFLAGS) -c $< -o $@

#NETTOYAGE DES FICHIERS OBJETS
clean:
	rm -f $(OBJ)

#NETTOYAGE COMPLET
fclean: clean
	rm -f $(NAME)

#RECONSTRUCTION COMPLETE
re: fclean all

.PHONY: all clean fclean re
