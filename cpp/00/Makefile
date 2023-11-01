NAME = magaphone

CPP = c++
CPPFLAG = -Wall -Wextra -Werror -std=c++98

SRCS = magaphone.cpp
OBJS = $(SRCS:.cpp=.o)

%.o: %.c
	$(CPP) $(CPPFLAG) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(CPP) $(CPPFLAG) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re