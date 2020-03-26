##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## my make file
##

NAME 	=	libsfml.so

SRCS  =	./src/Sfml.cpp \

TEST_SRC = ./src/main.cpp \

OBJS	=	$(SRCS:.cpp=.o)

NBR_OF_FILES := $(words $(SRCS))

CC	=	g++

RM	=	rm -f

MV	= 	mv -f

CPPFLAGS = -I ./include/ -I ./../
CPPFLAGS += -W -Wall -Wextra -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

all: $(NAME)

test: re
	  @ $(CC) $(TEST_SRC) -o test -ldl $(CPPFLAGS)
	  @ echo "\033[1;34mBinary : \033[1;32mtest\033[1;34m created sucesfully.\033[0m"
	  @ export LD_LIBRARY_PATH=$(PWD) && ./test

$(NAME): $(OBJS)
		 @ echo "\033[1;36m[ FILES COMPILED ] \033[0m \033[1;34m$(NBR_OF_FILES)\033[0m"
		 @ $(CC) -shared -o $(NAME) $(OBJS) $(CPPFLAGS)
		 @ echo "\033[1;34mLibrary : \033[1;32m$(NAME)\033[1;34m created sucesfully.\033[0m"
		 @ $(MV) $(NAME) ./../

clean:
		@ echo "\033[3;31mRemoving: \033[0m"
		@ echo "\033[3;31m$(OBJS)\033[0m" | tr ' ' '\n'
		@ $(RM) $(OBJS)

fclean:	clean
		@ echo "\033[3;31m./$(NAME)\033[0m"
		@ $(RM) $(NAME)
		@ $(RM) ./../$(NAME)

re: fclean all

%.o:	%.cpp
	@ echo "\033[1;34m[ OK ]\033[0m Compiling" $<
	@ $(CC) -o $@ -c $< $(CPPFLAGS) -fPIC

.PHONY: all clean fclean re test