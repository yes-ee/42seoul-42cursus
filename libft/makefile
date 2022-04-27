CC = gcc
CFLAGS = -Wall -Wextra -Werror
OBJS = $(SRCS:.c=.o) 
SRCS = srcs/ft_putchar.c srcs/ft_swap.c srcs/ft_putstr.c srcs/ft_strlen.c srcs/ft_strcmp.c
INC = -I ./includes
NAME = libft.a
RM = rm -f
 
all : $(NAME)
$(NAME) : $(OBJS)
	ar rc $@ $(OBJS)

%.o: %.c 
	$(CC) $(INC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re : fclean all
