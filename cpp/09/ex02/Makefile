NAME = PmergeMe

CXX = c++
CXXFLAG = -Wall -Wextra -Werror -std=c++98 -fsanitize=address -g

SRCS = main.cpp \
	PmergeMe.cpp

OBJS = $(SRCS:.cpp=.o)

%.o: %.cpp %.hpp
	$(CXX) $(CXXFLAG) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAG) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re