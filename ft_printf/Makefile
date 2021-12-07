CC = gcc
# ifdef WITH_DEBUG
	CFLAGS = -g3 -Wall -Wextra -Werror
# else
# 	CFLAGS = -Wall -Wextra -Werror
# endif

NAME = libftprintf.a
LIBFT = libft
AR = ar rcs

SRC_FILE = ft_printf ft_convert_char ft_convert_string ft_convert_int ft_convert_ptr ft_convert_uint
SRC = $(addsuffix .c, $(SRC_FILE))
OBJ = $(addsuffix .o, $(SRC_FILE))

all : $(NAME)

$(NAME) : $(OBJ)
	make -C $(LIBFT)
	cp libft/libft.a .
	mv libft.a $(NAME)
	$(AR) $(NAME) $(OBJ)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean : 
	rm -rf $(OBJ)
	make fclean -C $(LIBFT)

fclean : clean
	rm -rf $(NAME)

re : fclean all

debug :
	make WITH_DEBUG=1 all

.PHONY : all clean fclean debug re