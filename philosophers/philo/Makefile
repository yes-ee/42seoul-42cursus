# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yeselee <yeselee@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/09 17:43:39 by yeselee           #+#    #+#              #
#    Updated: 2023/01/17 21:14:15 by yeselee          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# SETUP
NAME		=	philo
CC			=	cc
CFLAGS		=	-Wall -Werror -Wextra
RM			=	rm -rf

# HEADER
HEADER_SRCS	=	philo.h
HEADER_DIR	=	./includes/
HEADER		=	$(addprefix $(HEADER_DIR), $(HEADER_SRCS))

# FILES
MPATH_SRCS	=	philo.c ft_atoi.c print_error.c init.c
MPATH_DIR	=	./srcs/
MPATH		=	$(addprefix $(MPATH_DIR), $(MPATH_SRCS))
OBJ_M		=	$(MPATH:.c=.o)

OBJ_R = $(OBJ_M)

#COMMANDS
%.o:			%.c $(HEADER) Makefile
				@$(CC) $(CFLAGS) -c $< -o $@

$(NAME):		$(OBJ_R)
				@$(CC) $(OBJ_R) -o $(NAME)
				@echo -e "$(GREEN)$(NAME) created!$(DEFAULT)"

all:			$(NAME)

clean:
				@$(RM) $(OBJ_M)
				@echo -e "$(YELLOW)object files deleted!$(DEFAULT)"

fclean:			clean
				@$(RM) $(NAME)
				@echo -e "$(RED)all deleted!$(DEFAULT)"

re:				fclean all

.PHONY:		all clean fclean bonus re

#COLORS
RED			=	\033[1;31m
GREEN		=	\033[1;32m
YELLOW		=	\033[1;33m
DEFAULT		=	\033[0m