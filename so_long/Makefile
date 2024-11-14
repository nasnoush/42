NAME    = so_long
CFLAGS  = -Wall -Wextra -Werror
CC      = gcc -I./minilibx -I./GNL
MLX     = -L./minilibx -lmlx -framework OpenGL -framework AppKit -lz
OBJ     = $(SRCS:.c=.o)

SRCS    = main.c GNL/get_next_line.c GNL/get_next_line_utils.c so_long.c player.c deplacement.c

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(MLX) -o $(NAME)

leaks : $(NAME)
	@echo "Test de leaks.."
	@leaks --atExit -- ./$<

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
