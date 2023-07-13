SERVER = server
CLIENT = client
B_SERVER = bserver
B_CLIENT = bclient

CC = cc
CFLAG = -Wall -Wextra -Werror

SRCS = server.c client.c
BSRCS = server_bonus.c client_bonus.c

OBJS = $(SRCS:.c=.o)
BOBJS = $(BSRCS:.c=.o)

%.o: %.c
	$(CC) $(CFLAG) -c $< -o $@

all: $(SERVER) $(CLIENT)

$(SERVER): server.o
	$(CC) server.o -o server
$(CLIENT): client.o
	$(CC) client.o -o client

bonus: $(B_SERVER) $(B_CLIENT)

$(B_SERVER): server_bonus.o
	$(CC) server_bonus.o -o server
$(B_CLIENT): client_bonus.o
	$(CC) client_bonus.o -o client

clean:
	rm -f $(OBJS)
	rm -f $(BOBJS)

fclean: clean
	rm -f $(SERVER) $(CLIENT)

re: fclean all

.PHONY: all clean fclean re bonus
