# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yejin <yejin@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/15 10:20:43 by yejin             #+#    #+#              #
#    Updated: 2022/06/15 16:11:50 by yejin            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

############## COMPILER ##############
cc	= g++

################ FLAG ################
ifdef DEBUG
	FLAGS	:= -Wall -Wextra -Werror -std=c++98 -g3 -fsanitize=address
else
	FLAGS	:= -Wall -Wextra -Werror -std=c++98
endif

############### TARGET ###############
NAME	= megaphone

################ FILE ################
SRCS	= megaphone.cpp

################ OBJ #################
OBJS	= $(SRCS:%.cpp=%.o)

################ RULE ################
all	: $(NAME)

$(NAME)	: $(OBJS)
	@$(cc) $(FLAGS) $^ -o $@
	@echo $(CUT)$(BOLD)complete COMPILE 🌸

%.o	: %.cpp
	@$(cc) $(FLAGS) -c $< -o $@
	@echo start COMPILE 🌟
	@echo current complie FLAGS : $(FLAGS)

clean	:
	@rm -f $(OBJS)
	@echo remove OBJ files 🌪

fclean : clean
	@rm -f $(NAME)
	@echo remove $(NAME) a.k.a target file 🎯

re : fclean all

debug :
	@make DEBUG=1
	@echo start DEBUG 😱 GOOD LUCK 🍀

.PHONY	: all clean fclean re debug