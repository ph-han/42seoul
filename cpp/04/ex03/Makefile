NAME = imple

CPP = c++
CPPFLAG = -Wall -Wextra -Werror -std=c++98 -fsanitize=address -g

SRCS = main.cpp \
	AMateria.cpp \
	Character.cpp \
	Cure.cpp \
	Ice.cpp \
	MateriaSource.cpp

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