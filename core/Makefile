##
## EPITECH PROJECT, 2020
## Arcade
## File description:
## Makefile core
##

NAME	=	../arcade

SRCS		= 	../Main.cpp								\
			$(wildcard ./src/*.cpp)					\
			$(wildcard ./../exception/src/*.cpp)		\
			
OBJS		=	$(SRCS:.cpp=.o)

NBR_OF_FILES := $(words $(SRCS))

CXX			=	g++

RM          =    rm -f

CPPFLAGS	=	-W -Wall -Wextra -I ./include/ -I ./../ -ldl

all: $(NAME)

$(NAME): $(OBJS)
		@ echo "\033[1;36m[ FILES COMPILED ] \033[0m \033[1;34m$(NBR_OF_FILES)\033[0m"
		@ $(CXX) $(OBJS) -o $(NAME) $(CPPFLAGS) 
		@ echo "\033[1;34mBinary : \033[1;32m$(NAME)\033[1;34m created sucesfully.\033[0m"

clean:
		@ echo "\033[3;31mRemoving: \033[0m"
		@ echo "\033[3;31m$(OBJS)\033[0m" | tr ' ' '\n'
		@ $(RM) $(OBJS)

fclean:	clean
		@ echo "\033[3;31m./$(NAME)\033[0m"
		@ $(RM) $(NAME)

%.o:	%.cpp
	@ echo "\033[1;34m[ OK ]\033[0m Compiling" $<
	@ $(CXX) -o $@ -c $< $(CPPFLAGS)

re: fclean all