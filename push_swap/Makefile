CC = gcc
CFLAGS = -Wall -Wextra -Werror

NAME = push_swap
FT_PRINTF = ft_printf

SRC_FILE = push_swap \
			stack_utils \
			parse_arg \
			sort_stack \
			sort_utils \
			stack_commands \
			cmd_utils

SRC = $(addsuffix .c, $(SRC_FILE))
OBJ = $(addsuffix .o, $(SRC_FILE))

all : $(NAME)

$(NAME) : $(OBJ)
	make bonus -C $(FT_PRINTF)
	$(CC) $(CFLAGS) -L./ft_printf -lftprintf -o $@ $(OBJ)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean : 
	rm -f $(OBJ)
	make fclean -C $(FT_PRINTF)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re