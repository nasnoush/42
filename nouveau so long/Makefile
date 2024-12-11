# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nadahman <nadahman@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/04 13:20:44 by nadahman          #+#    #+#              #
#    Updated: 2024/12/11 13:58:25 by nadahman         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = so_long
CFLAGS  = -Wall -Wextra -Werror #-fsanitize=address
CC      = gcc -I./minilibx -I./GNL
MLX     = -L./minilibx -lmlx -framework OpenGL -framework AppKit -lz
OBJ     = $(SRCS:.c=.o)

SRCS    = main.c GNL/get_next_line.c GNL/get_next_line_utils.c read_map.c player.c deplacement.c error.c affichage.c keycode.c keycode2.c printf/ft_printf.c printf/fonctions.c printf/fonctions2.c deplacement2.c verif.c verif2.c main2.c verif3.c

MAP_FILE = map.ber

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(MLX) -o $(NAME)

leaks : $(NAME)
	@echo "Test de leaks.."
	@leaks --atExit -- ./$< $(MAP_FILE)

norminette : $(NAME)
	@echo "Norminette en cours.."
	@norminette $(SRCS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
