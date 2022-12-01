# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yeselee <yeselee@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/24 20:41:57 by yeselee           #+#    #+#              #
#    Updated: 2022/12/01 17:26:43 by yeselee          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# SETUP
NAME		=	so_long
CC			=	cc
CFLAGS		=	-Wall -Werror -Wextra
RM			=	rm -rf
MLX			=  -lmlx -framework OpenGL -framework AppKit

# HEADER
HEADER_SRCS	=	so_long.h so_long_bonus.h
HEADER_DIR	=	includes/
HEADER		=	$(addprefix $(HEADER_DIR), $(HEADER_SRCS))

LFT_DIR = ./libft
LFT_FLAG = -L$(LFT_DIR) -lft -I$(LFT_DIR)

# FILES
MPATH_SRCS	=	close.c main.c map_check.c mlx_utils.c move.c obj_init.c utils.c map_validate.c
MPATH_DIR	=	mandatory/
MPATH		=	$(addprefix $(MPATH_DIR), $(MPATH_SRCS))
OBJ_M		=	$(MPATH:.c=.o)

BPATH_SRCS	=	close_bonus.c main_bonus.c map_check_bonus.c mlx_utils_bonus.c move_a_bonus.c \
move_w_bonus.c move_s_bonus.c move_d_bonus.c obj_init_bonus.c utils_bonus.c enemy_move_bonus.c \
enemy_move2_bonus.c put_image_rd_bonus.c map_validate_bonus.c

BPATH_DIR	=	bonus/
BPATH		=	$(addprefix $(BPATH_DIR), $(BPATH_SRCS))
OBJ_B		=	$(BPATH:.c=.o)

FUNC 		=	gnl/get_next_line.c gnl/get_next_line_utils.c
OBJ_F		=	$(FUNC:.c=.o)

ifdef WITH_BONUS
	OBJ_R = $(OBJ_B)
else
	OBJ_R = $(OBJ_M)
endif

#COMMANDS
%.o:			%.c $(HEADER) Makefile
				@$(CC) $(CFLAGS) -c $< -o $@

$(NAME):		$(OBJ_F) $(OBJ_R)
				@make -s -C $(LFT_DIR) all
				@$(CC) $(LFT_FLAG) $(OBJ_F) $(OBJ_R) $(MLX) -o $(NAME)
				@echo -e "$(GREEN)$(NAME) created!$(DEFAULT)"

all:			$(NAME)

bonus:
	make WITH_BONUS=1

clean:
				@make -s -C $(LFT_DIR) clean
				@$(RM) $(OBJ_M)
				@$(RM) $(OBJ_F)
				@$(RM) $(OBJ_B)
				@echo -e "$(YELLOW)object files deleted!$(DEFAULT)"

fclean:			clean
				@make -s -C $(LFT_DIR) fclean
				@$(RM) $(NAME)
				@echo -e "$(RED)all deleted!$(DEFAULT)"

re:				fclean all

.PHONY:		all clean fclean bonus re

#COLORS
RED			=	\033[1;31m
GREEN		=	\033[1;32m
YELLOW		=	\033[1;33m
DEFAULT		=	\033[0m