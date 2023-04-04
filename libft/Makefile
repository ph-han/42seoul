NAME = libft.a

CC = cc
CFLAG = -Wall -Wextra -Werror

SRCS = ft_isascii.c ft_strlen.c  ft_toupper.c \
	   ft_atoi.c ft_isdigit.c  ft_strncmp.c \
	   ft_isalnum.c ft_isprint.c ft_strrchr.c \
	   ft_isalpha.c ft_strchr.c  ft_tolower.c \
	   ft_strlcpy.c ft_strlcat.c ft_strnstr.c \
	   ft_bzero.c ft_memset.c ft_memchr.c \
	   ft_memcmp.c ft_memcpy.c ft_memmove.c \
	   ft_calloc.c ft_strdup.c \
	   ft_substr.c ft_strjoin.c ft_strtrim.c \
	   ft_split.c ft_itoa.c ft_strmapi.c \
	   ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c \
	   ft_putendl_fd.c ft_putnbr_fd.c

SRCS_BN = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c \
		  ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
		  ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c

ifdef WITH_BONUS
	OBJS = $(SRCS:.c=.o) $(SRCS_BN:.c=.o)
else
	OBJS = $(SRCS:.c=.o)
endif


%.o: %.c
	$(CC) $(CFLAG) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	ar rsc $(NAME) $(OBJS)

clean:
	rm -f $(OBJS) $(SRCS_BN:.c=.o)

fclean: clean
	rm -f $(NAME)

re: fclean all

bonus : $(OBJS)
	@sleep 1
	@make WITH_BONUS=1 all

.PHONY: all clean fclean re bonus
