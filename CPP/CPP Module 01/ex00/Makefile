# SETUP
NAME		=	zombie
CXX			=	c++
CXXFLAGS	=	-Wall -Wextra -Werror -std=c++98
RM			=	rm -rf

# FILES
SRCS	=	Zombie.cpp main.cpp newZombie.cpp randomChump.cpp
OBJ_M		=	$(SRCS:.cpp=.o)

#COMMANDS
.o:				.cpp
				$(CXX) $(CXXFLAGS) -c $(SRCS)

$(NAME):		$(OBJ_M)
				$(CXX) $(OBJ_M) -o $(NAME)

all:			$(NAME)

clean:
				$(RM) $(OBJ_M)

fclean:			clean
				$(RM) $(NAME)

re:				fclean all

.PHONY:		all clean fclean re
