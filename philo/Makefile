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

NAME = philo

CC = cc
CFLAG = -Wall -Wextra -Werror
INCLUDES = -Iincludes
DEBUG =  -g -fsanitize=thread

SRCS = main.c routine.c utils.c monitor.c routine_utils.c

OBJS = $(SRCS:.c=.o)

%.o: %.c
	@$(CC) $(CFLAG) $(INCLUDES) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(OBJS) -o $(NAME)
	@echo $(GREEN)"philo made." $(EOC)

clean:
	@rm -f $(OBJS)
	@echo $(GREEN)"clean." $(EOC)

fclean: clean
	@rm -f $(NAME)
	@echo $(GREEN)"fclean." $(EOC)

re: fclean all

.PHONY: all clean fclean re