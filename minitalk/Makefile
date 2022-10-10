NAME = minitalk
SERVER = server
CLIENT = client

SERVER_DIR = ./mandatory/server
CLIENT_DIR = ./mandatory/client

SERVER_B_DIR = ./bonus/server
CLIENT_B_DIR = ./bonus/client

SERVER_FILES = server.c \
			   utils.c

CLIENT_FILES = client.c \
			   utils.c

SERVER_B_FILES = server_bonus.c \
			   utils_bonus.c

CLIENT_B_FILES = client_bonus.c \
			   utils_bonus.c

SERVER_A = $(addprefix $(SERVER_DIR)/, $(SERVER_FILES:.c=.o))
CLIENT_A = $(addprefix $(CLIENT_DIR)/, $(CLIENT_FILES:.c=.o))

SERVER_B = $(addprefix $(SERVER_B_DIR)/, $(SERVER_B_FILES:.c=.o))
CLIENT_B = $(addprefix $(CLIENT_B_DIR)/, $(CLIENT_B_FILES:.c=.o))

SERVER_OBJS = $(SERVER_A:.c=.o)
CLIENT_OBJS = $(CLIENT_A:.c=.o)

SERVER_B_OBJS = $(SERVER_B:.c=.o)
CLIENT_B_OBJS = $(CLIENT_B:.c=.o)

# C = cc
# CFLAGS = -Wall -Werror -Wextra

# NAME = minitalk

# # HEADER
# HEADER_SRCS	=	minitalk.h pipex_bonus.h
# HEADER_DIR	=	includes/
# HEADER		=	$(addprefix $(HEADER_DIR), $(HEADER_SRCS))

# SERVER_FILES = server.c \
# 			   utils.c

# CLIENT_FILES = client.c \
# 			   utils.c


# MPATH_SRCS	=	utils.c client.c server.c
# MPATH_DIR	=	mandatory/
# MPATH		=	$(addprefix $(MPATH_DIR), $(MPATH_SRCS))
# OBJ_M		=	$(MPATH:.c=.o)

%.o:			%.c $(HEADER) Makefile
				${CC} ${CFLAGS} -c $< -o $@

# # %.o: %.c 
# # 	$(CC) $(CFLAGS) -c $< -o $@

# # $(NAME): $(OBJ)
# # 	ar rc $@ $^

$(NAME):		$(SERVER_OBJS) $(CLIENT_OBJS)
				$(CC) $(SERVER_OBJS) -o $(SERVER)
				$(CC) $(CLIENT_OBJS) -o $(CLIENT)

all: $(NAME)

bonus:  fclean $(SERVER_B_OBJS) $(CLIENT_B_OBJS)
				$(CC) $(SERVER_B_OBJS) -o $(SERVER)
				$(CC) $(CLIENT_B_OBJS) -o $(CLIENT)

clean:
	rm -rf $(OBJ) $(OBJ_B)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: bonus all clean fclean re
