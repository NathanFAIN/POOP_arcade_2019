##
## EPITECH PROJECT, 2020
## Arcade
## File description:
## Makefile core
##

CXX		=	g++

CFLAGS	=	-Wall -Wextra -g3

SRC		= 	../Main.cpp								\
			$(wildcard src/*.cpp)					\
			$(wildcard ../exception/src/*.cpp)		\
			

OBJ		=	$(SRC:.cpp=.o)

NAME	=	../arcade

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all