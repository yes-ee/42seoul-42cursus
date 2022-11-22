CC = gcc
CFLAGS = -Wall -Wextra -Werror
FLAGS = -lmlx -framework OpenGL -framework AppKit
OBJS = $(SRCS:.c=.o) 
NAME = so_long
RM = rm -rf
SRCS = so_long.c \

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(FLAGS) -o $(NAME) $(OBJS)

%.o: %.c 
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY : all clean fclean re