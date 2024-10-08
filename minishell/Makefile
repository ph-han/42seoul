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

LIBFT		=	./libft/libft.a
SRCDIR		=	./src
SRC			=	dequotenizer.c expand.c expand_utils.c expand_utils2.c hello.c\
				export_util.c ft_cd.c ft_echo.c ft_env.c ft_exit.c ft_export.c ft_pwd.c ft_unset.c \
				handler.c heredoc.c init_redir.c is_built_in.c \
				main.c make_envp.c \
				pipeline_util.c pipeline_utils2.c pipeline.c \
				struct_cmd_utils.c struct_cmd.c syntax_analyzer.c \
				tokenizer.c utils.c utils2.c utils3.c utils4.c utils5.c \
				child_proc.c child_util.c
SRC			:=	$(addprefix $(SRCDIR)/, $(SRC))
OBJ			=	$(SRC:.c=.o)

NAME		= minishell
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
LDFLAGS		= -L/Users/$(USER)/.brew/opt/readline/lib -lreadline
LIBFLAGS	= -Llibft -lft 
INCLUDES	= -Ilibft -I/Users/$(USER)/.brew/opt/readline/include

all:		$(NAME)

$(NAME): 	$(OBJ) $(LIBFT)
		@$(CC) $(LIBFLAGS) $(LDFLAGS) -g $(OBJ) -o $(NAME)
		@echo $(GREEN)"minishell made." $(EOC)

$(LIBFT):
		@make --no-print-directory -C ./libft bonus

%.o: 		%.c
		@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
		@make --no-print-directory -C ./libft clean
		@$(RM) $(OBJ)
		@echo $(GREEN)"cleaned." $(EOC)

fclean:		clean
		@make --no-print-directory -C ./libft fclean
		@$(RM) $(NAME)
		@echo $(GREEN)"fcleaned." $(EOC)

re:			fclean all

.PHONY:		clean fclean re
