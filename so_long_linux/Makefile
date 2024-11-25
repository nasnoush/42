# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nadahman <nadahman@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/25 10:31:49 by nadahman          #+#    #+#              #
#    Updated: 2024/11/25 13:59:47 by nadahman         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = so_long
CFLAGS  = -Wall -Wextra -Werror
CC      = gcc
MLX_DIR = ./mlx_linux
MLX_FLAGS = -L$(MLX_DIR) -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz
INCLUDES = -I./GNL -I$(MLX_DIR)

SRCS    = main.c \
          GNL/get_next_line.c \
          GNL/get_next_line_utils.c \
          read_map.c \
          player.c \
          deplacement.c \
          error.c \
          affichage.c \
          keycode.c \
          keycode2.c \
          printf/ft_printf.c \
          printf/fonctions.c \
          printf/fonctions2.c

OBJ     = $(SRCS:.c=.o)

all: $(NAME)

$(MLX_DIR)/libmlx_Linux.a:
	make -C $(MLX_DIR)

$(NAME): $(OBJ) $(MLX_DIR)/libmlx_Linux.a
	$(CC) $(OBJ) $(MLX_FLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -O3 -c $< -o $@

clean:
	rm -f $(OBJ)
	make clean -C $(MLX_DIR)

fclean: clean
	rm -f $(NAME)
	make clean -C $(MLX_DIR)

re: fclean all

leaks: $(NAME)
	@echo "Test de fuites.."
	@valgrind --leak-check=full ./$<

.PHONY: all clean fclean re leaks
