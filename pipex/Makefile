CC = gcc
#CFLAGS = -Wall -Wextra -Werror
NAME = pipex
LIBFT = libft
SRC_FILE = pipex \
		initialize \
		execute_cmds \
		redirection

SRC = $(addsuffix .c, $(SRC_FILE))
OBJ = $(addsuffix .o, $(SRC_FILE))

all : $(NAME)

$(NAME) : $(OBJ)
	make -C $(LIBFT)
	$(CC) $(CFLAGS) -L $(LIBFT) -lft $^ -o $@

clean :
	make fclean -C $(LIBFT)
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re