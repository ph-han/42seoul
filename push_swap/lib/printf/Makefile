NAME = libftprintf.a

CC = cc
CFLAG = -Wall -Wextra -Werror

SRCS = ft_printf.c

OBJS = $(SRCS:.c=.o)


%.o: %.c
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
