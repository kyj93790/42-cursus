# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yejin <yejin@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/10 02:03:20 by yejin             #+#    #+#              #
#    Updated: 2022/04/10 02:04:47 by yejin            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror

NAME = push_swap
CHECKER = checker
FT_PRINTF = ft_printf
GNL = gnl

SRC_FILE = push_swap \
			parse_arg \
			sort_stack \
			sort_stack_utils \
			sort_piece \
			stack_commands \
			stack_commands_rotate \
			stack_commands_utils \
			cmd_utils
B_SRC_FILE = checker_bonus \
				parse_arg_bonus \
				stack_commands_default_bonus \
				stack_commands_merge_bonus \
				stack_commands_rotate_bonus \
				stack_commands_utils_bonus \
				gnl/get_next_line \
				gnl/get_next_line_utils
SRC = $(addsuffix .c, $(SRC_FILE))
B_SRC = $(addsuffix .c, $(B_SRC_FILE))
OBJ = $(addsuffix .o, $(SRC_FILE))
B_OBJ = $(addsuffix .o, $(B_SRC_FILE))

all : $(NAME)

$(NAME) : $(OBJ)
	make bonus -C $(FT_PRINTF)
	$(CC) $(CFLAGS) -L./ft_printf -lftprintf -o $@ $(OBJ)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean : 
	rm -f $(OBJ)
	make fclean -C $(FT_PRINTF)
	rm -f $(B_OBJ)

fclean : clean
	rm -f $(NAME)
	rm -f $(CHECKER)

re : fclean all

bonus : $(CHECKER)

$(CHECKER) : $(B_OBJ)
	make bonus -C $(FT_PRINTF)
	$(CC) $(CFLAGS) -L./ft_printf -lftprintf -o $@ $(B_OBJ)

.PHONY : all clean fclean re