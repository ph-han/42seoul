NAME = libft.a

CC = gcc
CFLAG = -Wall -Wextra -Werror

SRCS = ft_isascii.c ft_strlen.c  ft_toupper.c \
ft_atoi.c    ft_isdigit.c ft_strncmp.c \
ft_isalnum.c ft_isprint.c ft_strrchr.c \
ft_isalpha.c ft_strchr.c  ft_tolower.c 

OBJS = $(SRCS:.c=.o)

.c.o: $(SRCS)
	$(CC) $(CFLAG) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	ar rsc $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
