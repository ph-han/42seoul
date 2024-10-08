#-------------------------------------------

BLACK       =   "\033[0;30m"
GRAY        =   "\033[1;30m"
RED         =   "\033[1;31m"
GREEN       =   "\033[0;32m"
YELLOW      =   "\033[1;33m"
PURPLE      =   "\033[0;35m"
CYAN        =   "\033[1;36m"
WHITE       =   "\033[1;37m"
EOC         =   "\033[0;0m"
LINE_CLEAR  =   "\x1b[1A\x1b[M"

#-------------------------------------------

NAME = libgnl.a

CC = cc
CFLAG = -Wall -Wextra -Werror

SRCS = get_next_line.c get_next_line_utils.c

OBJS = $(SRCS:.c=.o)


%.o: %.c
	@$(CC) $(CFLAG) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	@ar rsc $(NAME) $(OBJS)
	@echo $(GREEN)"gnl made." $(EOC)

clean:
	@rm -f $(OBJS) $(SRCS_BN:.c=.o)
	@echo $(GREEN)"gnl cleaned." $(EOC)

fclean: clean
	@rm -f $(NAME)
	@echo $(GREEN)"gnl fcleaned." $(EOC)

re: fclean all

.PHONY: all clean fclean re bonus
