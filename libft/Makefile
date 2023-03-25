NAME = libft.a

CC = gcc
CFLAG = -Wall -Wextra -Werror

INCOUDE = libft.h 

SRCS = ft_isascii.c ft_strlen.c  ft_toupper.c \
ft_atoi.c ft_isdigit.c  ft_strncmp.c\
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

SRCS_BN = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c \
		  ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c

OBJS = $(SRCS:.c=.o)

OBJS_BONUS = $(SRCS_BN:.c=.o)

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

bonus : $(OBJS) $(OBJS_BONUS)
	$(AR) $(ARFLAGS) $(NAME) $^

.PHONY: all clean fclean re
