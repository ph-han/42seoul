#-----------------------------------------

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

NAME = fdf
NAME_BONUS = fdf_bonus
INCLUDE = -Iincludes
LIBFT = -lft
LIBFT_DIR = ./includes/libft
GNL_DIR = ./includes/get_next_line

MLX = -Lmlx -lmlx -framework OpenGL -framework Appkit
MLX_DIR = ./mlx

CC = gcc
CFLAG = -Wall -Wextra -Werror

SRCS = main.c rotate_metrix.c scaling.c draw.c line_algo.c \
	init.c utils.c check.c\
	parse.c parse_utils.c\
	projection.c \
	./includes/get_next_line/get_next_line.c ./includes/get_next_line/get_next_line_utils.c

SRCS_BONUS = ./bonus/main_bonus.c ./bonus/rotate_metrix_bonus.c ./bonus/scaling_bonus.c \
	./bonus/draw_bonus.c ./bonus/line_algo_bonus.c \
	./bonus/init_bonus.c ./bonus/utils_bonus.c ./bonus/check_bonus.c \
	./bonus/rotate_map_bonus.c ./bonus/color_bonus.c\
	./bonus/parse_bonus.c ./bonus/parse_utils_bonus.c \
	./bonus/projection_bonus.c ./bonus/zoom_bonus.c ./bonus/move_bonus.c \
	./includes/get_next_line/get_next_line.c ./includes/get_next_line/get_next_line_utils.c

OBJS = $(SRCS:.c=.o)

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

%.o: %.c
	$(CC) $(CFLAG) $(INCLUDE)/libft -Imlx $(INCLUDE) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	@$(MAKE) -C $(MLX_DIR)
	@$(MAKE) -C $(LIBFT_DIR)
	$(CC) $(CFLAG) $(OBJS) -L$(LIBFT_DIR) $(LIBFT) $(MLX) -o $(NAME)
	@echo $(GREEN)"\n==========================================================\n"$(EOC)
	@echo $(YELLOW)"                        FDF DONE"$(EOC)
	@echo $(GREEN)"\n==========================================================\n"$(EOC)

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJS_BONUS)
	@rm -f $(NAME)
	@$(MAKE) -C $(MLX_DIR)
	@$(MAKE) -C $(LIBFT_DIR)
	$(CC) $(CFLAG) $(OBJS_BONUS) -L$(LIBFT_DIR) $(LIBFT) $(MLX) -o $(NAME)
	@echo $(GREEN)"\n==========================================================\n"$(EOC)
	@echo $(YELLOW)"                      FDF BONUS DONE"$(EOC)
	@echo $(GREEN)"\n==========================================================\n"$(EOC)

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean
	rm -f $(OBJS) $(OBJS_BONUS) $(SRCS_BN:.c=.o)
	@echo $(GREEN)"\n==========================================================\n"$(EOC)
	@echo $(YELLOW)"                       FDF CLEAN DONE"$(EOC)
	@echo $(GREEN)"\n==========================================================\n"$(EOC)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)
	@echo $(GREEN)"\n==========================================================\n"$(EOC)
	@echo $(YELLOW)"                      FDF FCLEAN DONE"$(EOC)
	@echo $(GREEN)"\n==========================================================\n"$(EOC)

re: fclean all

.PHONY: all clean fclean re bonus
