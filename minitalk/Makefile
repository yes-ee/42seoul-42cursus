NAME = minitalk
SERVER = server
CLIENT = client

SERVER_SRCS = server.c \
			   utils.c

CLIENT_SRCS = client.c \
			   utils.c

SERVER_OBJS = $(SERVER_SRCS:.c=.o)
CLIENT_OBJS = $(CLIENT_SRCS:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror

HEADER_SRCS	=	minitalk.h

%.o:			%.c
				$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME):		$(SERVER) $(CLIENT)
				
$(SERVER):	$(SERVER_OBJS)
				$(CC) $(CFLAGS) -o $(SERVER) $(SERVER_OBJS)
				
$(CLIENT):	$(CLIENT_OBJS)
				$(CC) $(CFLAGS) -o $(CLIENT) $(CLIENT_OBJS)
				

clean:
	rm -rf $(SERVER_OBJS) $(CLIENT_OBJS)

fclean: clean
	rm -f $(SERVER) $(CLIENT)

re: fclean all

.PHONY: all clean fclean re
