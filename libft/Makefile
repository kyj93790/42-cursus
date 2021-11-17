CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = libft.a
SRCS = ft_atoi.c \
	   ft_bzero.c \
	   ft_calloc.c \
	   ft_isalnum.c \
	   ft_isalpha.c \
	   ft_isascii.c \
	   ft_isprint.c \
	   ft_memchr.c \
	   ft_memcpy.c \
	   ft_memmove.c \
	   ft_memset.c \
	   ft_strchr.c \
	   ft_strdup.c \
	   ft_strlcat.c \
	   ft_strlcpy.c \
	   ft_strlen.c \
	   ft_strncmp.c \
	   ft_strnstr.c \
	   ft_strrchr.c \
	   ft_tolower.c \
	   ft_toupper.c \
	   ft_substr.c \
	   ft_strjoin.c \
	   ft_split.c \
	   ft_itoa.c \
	   ft_strmapi.c \
	   ft_striteri.c \
	   ft_putchar_fd.c \
	   ft_putstr_fd.c \
	   ft_putendl_fd.c \
	   ft_putnbr_fd.c
B_SRCS = ft_lstnew.c
OBJECTS = $(SRCS:.c=.o)
B_OBJECTS = $(B_SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJECTS)
	ar rcs $(NAME) $(OBJECTS)

bonus : $(OBJECTS) $(B_OBJECTS)
	ar rcs $(NAME) $(OBJECTS) $(B_OBJECTS)

clean :
	rm -f $(OBJECTS) $(B_OBJECTS)

fclean : clean
	rm -f $(NAME)

re : fclean all
