CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = pipex
LIBFT = libft

SRC_FILE = pipex \
		initialize \
		execute_cmds \
		calc_status \
		redirect
B_SRC_FILE = pipex \
			initialize \
			execute_cmds \
			calc_status \
			get_next_line \
			get_next_line_utils \
			heredoc \
			redirect

SRC = $(addsuffix .c, $(SRC_FILE))
OBJ = $(addsuffix .o, $(SRC_FILE))
B_SRC = $(addsuffix _bonus.c, $(B_SRC_FILE))
B_OBJ = $(addsuffix _bonus.o, $(B_SRC_FILE))

ifdef WITH_BONUS
	OBJ_FILES = $(B_OBJ)
else
	OBJ_FILES = $(OBJ)
endif

all : $(NAME)

$(NAME) : $(OBJ_FILES)
	make -C $(LIBFT)
	$(CC) $(CFLAGS) -L $(LIBFT) -lft $^ -o $@

clean :
	make fclean -C $(LIBFT)
	rm -f $(OBJ)
	rm -f $(B_OBJ)
	rm -f temp_file

fclean : clean
	rm -f $(NAME)

re : fclean all

bonus : $(B_OBJ)
	make WITH_BONUS=1 all
	
.PHONY : all clean fclean re bonus