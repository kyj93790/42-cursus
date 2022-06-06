# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yejikim <yejikim@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/04 16:57:22 by yejikim           #+#    #+#              #
#    Updated: 2022/06/06 13:20:07 by yejikim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

cc = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = philo_bonus
SRC_FILE = main \
			initialize \
			philo_utils \
			routine \
			monitor \
			print_state \
			handle_error \
			free_mem

SRC = $(addsuffix _bonus.c, $(SRC_FILE))
OBJ = $(addsuffix _bonus.o, $(SRC_FILE))

all : $(NAME)

$(NAME) : $(OBJ)
	$(cc) $(CFLAGS) $^ -o $@

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all

PHONY : all clean fclean re