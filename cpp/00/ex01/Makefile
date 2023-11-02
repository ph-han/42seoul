NAME = phonebook

CPP = c++
CPPFLAG = -Wall -Wextra -Werror -std=c++98

SRCS = phonebook.cpp main.cpp contact.cpp
OBJS = $(SRCS:.cpp=.o)

%.o: %.cpp
	$(CPP) $(CPPFLAG) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(CPP) $(CPPFLAG) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re