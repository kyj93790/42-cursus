cc = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = philo
SRC_FILE = main \
			initialize \
			philo_utils \
			routine \
			routine_one \
			monitor \
			print_state \
			handle_error \
			free_mem

SRC = $(addsuffix .c, $(SRC_FILE))
OBJ = $(addsuffix .o, $(SRC_FILE))

all : $(NAME)

$(NAME) : $(OBJ)
	$(cc) $(CFLAGS) $^ -o $@

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all

PHONY : all clean fclean re