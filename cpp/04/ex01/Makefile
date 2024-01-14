NAME = animal

CPP = c++
CPPFLAG = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp Animal.cpp Cat.cpp Dog.cpp Brain.cpp WrongAnimal.cpp WrongCat.cpp
OBJS = $(SRCS:.cpp=.o)

%.o: %.cpp %.hpp
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