CC = gcc
FLAGS = -Wall -Wextra -Werror

NAME = so_long

SRC_FILE = so_long \
			read_file \
			check_map
SRC = $(addsuffix .c, $(SRC_FILE))
OBJ = $(addsuffix .o, $(SRC_FILE))
MLX = minilibx_opengl_20191021
LIBFT = libft

all : $(NAME)

$(NAME) : $(OBJ)
	make -C $(LIBFT)
	make -C $(MLX)
	$(CC) -I $(MLX) $(SRC) -L $(LIBFT) -lft -L $(MLX) -lmlx -framework OpenGL -framework AppKit -o $@

clean :
	rm -f $(OBJ)
	make fclean -C $(LIBFT)
	make clean -C $(MLX)
	rm -f $(MLX)/libmlx

fclean : clean
	rm -f $(NAME)