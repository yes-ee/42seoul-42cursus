# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yeselee <yeselee@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/24 20:41:57 by yeselee           #+#    #+#              #
#    Updated: 2022/11/27 15:08:45 by yeselee          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# SETUP
NAME = minitalk
SERVER = server
CLIENT = client
CC = cc
CFLAGS = -Wall -Werror -Wextra
RM = rm -rf

# HEADER
HEADER_SRCS = minitalk.h minitalk_bonus.h
HEADER_DIR = includes/
HEADER = $(addprefix $(HEADER_DIR), $(HEADER_SRCS))

# FILES
MPATH_DIR = mandatory/

MPATH_SERVER_SRCS = server.c utils.c
MPATH_CLIENT_SRCS = client.c utils.c

MPATH_SERVER = $(addprefix $(MPATH_DIR), $(MPATH_SERVER_SRCS))
MPATH_CLIENT = $(addprefix $(MPATH_DIR), $(MPATH_CLIENT_SRCS))

SERVER_OBJS_M = $(MPATH_SERVER:.c=.o)
CLIENT_OBJS_M = $(MPATH_CLIENT:.c=.o)

BPATH_DIR	=	bonus/

BPATH_SERVER_SRCS = server_bonus.c utils_bonus.c
BPATH_CLIENT_SRCS = client_bonus.c utils_bonus.c

BPATH_SERVER = $(addprefix $(BPATH_DIR), $(BPATH_SERVER_SRCS))
BPATH_CLIENT = $(addprefix $(BPATH_DIR), $(BPATH_CLIENT_SRCS))

SERVER_OBJS_B = $(BPATH_SERVER:.c=.o)
CLIENT_OBJS_B = $(BPATH_CLIENT:.c=.o)

#COMMANDS
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(SERVER) $(CLIENT)

$(SERVER): $(SERVER_OBJS_M)
			$(CC) $(CFLAGS) -o $(SERVER) $(SERVER_OBJS_M)

$(CLIENT): $(CLIENT_OBJS_M)
			$(CC) $(CFLAGS) -o $(CLIENT) $(CLIENT_OBJS_M)

all: $(NAME)

bonus: fclean $(SERVER_OBJS_B) $(CLIENT_OBJS_B)
		$(CC) $(SERVER_OBJS_B) -o $(SERVER)
		$(CC) $(CLIENT_OBJS_B) -o $(CLIENT)


clean:
		$(RM) $(SERVER_OBJS_M) $(CLIENT_OBJS_M)
		$(RM) $(SERVER_OBJS_B) $(CLIENT_OBJS_B)

fclean: clean
		$(RM) $(SERVER) $(CLIENT)

re: fclean all

.PHONY: all clean fclean bonus re
