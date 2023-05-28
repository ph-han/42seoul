NAME = push_swap
LIBFT = -lft
LIBFT_DIR = ./includes/libft
FTPRINTF = -lftprintf
FTPRINTF_DIR = ./includes/printf

CC = cc
CFLAG = -Wall -Wextra -Werror

SRCS = main.c utils.c \
	operations/stack.c \
	operations/push_swap/push.c \
	operations/push_swap/reverse_rotate.c \
	operations/push_swap/rotate.c \
	operations/push_swap/swap.c

OBJS = $(SRCS:.c=.o)

%.o: %.c
	$(CC) $(CFLAG) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C $(LIBFT_DIR)
	$(MAKE) -C $(FTPRINTF_DIR)
	gcc $(OBJS) -L$(LIBFT_DIR) $(LIBFT) -L$(FTPRINTF_DIR) $(FTPRINTF) -o $(NAME)

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(FTPRINTF_DIR) clean
	rm -f $(OBJS) $(SRCS_BN:.c=.o)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(FTPRINTF_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
