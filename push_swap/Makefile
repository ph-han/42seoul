NAME = push_swap
BONUS_NAME = checker
LIBFT = -lft
LIBFT_DIR = ./includes/libft
FTPRINTF = -lftprintf
FTPRINTF_DIR = ./includes/printf
GNL_DIR = ./includes/get_next_line

CC = cc
CFLAG = -Wall -Wextra -Werror

SRCS = main.c sort.c mini_sort.c \
	sort_utils1.c sort_utils2.c sort_utils3.c sort_utils4.c sort_utils5.c push_swap_utils.c \
	operations/stack.c \
	operations/push_swap/push.c \
	operations/push_swap/reverse_rotate.c \
	operations/push_swap/rotate.c \
	operations/push_swap/swap.c

BONUS_SRCS = ./bonus/main_bonus.c ./bonus/checker_utils.c ./bonus/check_bonus.c \
	./bonus/op_push_bonus.c ./bonus/op_reverse_rotate_bonus.c \
	./bonus/op_rotate_bonus.c ./bonus/op_swap_bonus.c ./bonus/stack_bonus.c \
	./includes/get_next_line/get_next_line.c ./includes/get_next_line/get_next_line_utils.c

OBJS = $(SRCS:.c=.o)

BONUS_OBJS = $(BONUS_SRCS:.c=.o)

%.o: %.c
	$(CC) $(CFLAG) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C $(LIBFT_DIR)
	$(MAKE) -C $(FTPRINTF_DIR)
	gcc $(OBJS) -L$(LIBFT_DIR) $(LIBFT) -L$(FTPRINTF_DIR) $(FTPRINTF) -o $(NAME)

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_OBJS)
	$(MAKE) -C $(LIBFT_DIR)
	$(MAKE) -C $(FTPRINTF_DIR)
	gcc $(BONUS_OBJS) -L$(LIBFT_DIR) $(LIBFT) -o $(BONUS_NAME)

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(FTPRINTF_DIR) clean
	rm -f $(OBJS) $(SRCS_BN:.c=.o)
	rm -f $(BONUS_OBJS) $(SRCS_BN:.c=.o)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(FTPRINTF_DIR) fclean
	rm -f $(NAME)
	rm -f $(BONUS_NAME)

re: fclean all

.PHONY: all clean fclean bonus re
