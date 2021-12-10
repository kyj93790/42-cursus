# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yejin <yejin@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/10 23:31:12 by yejin             #+#    #+#              #
#    Updated: 2021/12/10 23:31:14 by yejin            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a
LIBFT = libft
AR = ar rcs

SRC_FILE = ft_printf \
			ft_convert_char \
			ft_convert_string \
			ft_convert_int \
			ft_convert_ptr \
			ft_convert_uint \
			ft_convert_lowerhex \
			ft_convert_upperhex \
			ft_convert_percent
SRC = $(addprefix mandatory/, $(addsuffix .c, $(SRC_FILE)))
OBJ = $(addprefix mandatory/, $(addsuffix .o, $(SRC_FILE)))
B_SRC = $(addprefix bonus/, $(addsuffix _bonus.c, $(SRC_FILE)))
B_OBJ = $(addprefix bonus/, $(addsuffix _bonus.o, $(SRC_FILE)))

ifdef WITH_BONUS
	OBJ_FILES = $(B_OBJ)
else
	OBJ_FILES = $(OBJ)
endif

all : $(NAME)

$(NAME) : $(OBJ_FILES)
	make -C $(LIBFT)
	cp libft/libft.a .
	mv libft.a $(NAME)
	$(AR) $(NAME) $(OBJ_FILES)

bonus :
	make WITH_BONUS=1 all

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean : 
	rm -f $(OBJ)
	rm -f $(B_OBJ)
	make fclean -C $(LIBFT)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean bonus re
