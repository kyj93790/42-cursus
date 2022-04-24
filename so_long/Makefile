# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yejin <yejin@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/24 14:02:09 by yejin             #+#    #+#              #
#    Updated: 2022/04/24 15:42:22 by yejin            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
FLAGS = -Wall -Wextra -Werror

NAME = so_long

SRC_FILE = so_long \
			read_file \
			check_map \
			init_game \
			put_elements \
			load_character_img \
			exec_game \
			free_game
SRC = $(addprefix mandatory/, $(addsuffix .c, $(SRC_FILE)))
OBJ = $(addprefix mandatory/, $(addsuffix .o, $(SRC_FILE)))
B_SRC = $(addprefix bonus/, $(addsuffix _bonus.c, $(SRC_FILE)))
B_OBJ = $(addprefix bonus/, $(addsuffix _bonus.o, $(SRC_FILE)))
MLX = minilibx_opengl_20191021
LIBFT = libft

ifdef WITH_BONUS
	OBJ_FILES = $(B_OBJ)
else
	OBJ_FILES = $(OBJ)
endif

all : $(NAME)

$(NAME) : $(OBJ_FILES)
	make -C $(LIBFT)
	make -C $(MLX)
	$(CC) $(FLAGS) -I $(MLX) -L $(LIBFT) -lft -L $(MLX) -lmlx -framework OpenGL -framework AppKit $^ -o $@

bonus : $(B_OBJ)
	make WITH_BONUS=1 all

clean :
	rm -f $(OBJ)
	rm -f $(B_OBJ)
	make fclean -C $(LIBFT)
	make clean -C $(MLX)
	rm -f $(MLX)/libmlx

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean bonus re