# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yejikim <yejikim@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/15 10:20:43 by yejin             #+#    #+#              #
#    Updated: 2022/07/03 18:35:35 by yejikim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

############## COMPILER ##############
cxx	= c++

################ FLAG ################
ifdef DEBUG
	FLAGS	:= -Wall -Wextra -Werror -std=c++98 -g3 -fsanitize=address
else
	FLAGS	:= -Wall -Wextra -Werror -std=c++98
endif

############### TARGET ###############
NAME	= a.out

################ FILE ################
SRCS	= main.cpp Fixed.cpp

################ OBJ #################
OBJS	= $(SRCS:%.cpp=%.o)

############### Color ################
GREEN="\033[32m"
L_GREEN="\033[1;32m"
RED="\033[31m"
L_RED="\033[1;31m"
RESET="\033[0m"
BOLD="\033[1m"
L_PUPLE="\033[1;35m"
L_CYAN="\033[1;96m"
UP = "\033[A"
CUT = "\033[K"

################ RULE ################
all	: $(NAME)

$(NAME)	: $(OBJS)
	@$(cxx) $(FLAGS) $^ -o $@
	@echo current complie FLAGS : $(FLAGS)
	@echo complete $(L_GREEN)COMPILE$(RESET) 🌸

%.o	: %.cpp
	@$(cxx) $(FLAGS) -c $< -o $@

clean	:
	@rm -f $(OBJS)
	@echo $(L_RED)remove$(RESET) OBJ files 🌪

fclean : clean
	@rm -f $(NAME)
	@echo $(L_RED)remove$(RESET) $(NAME) a.k.a target file 🎯

re : fclean all

debug :
	@make DEBUG=1
	@echo start $(L_CYAN)DEBUG$(RESET) 😱 GOOD LUCK 🍀

.PHONY	: all clean fclean re debug
