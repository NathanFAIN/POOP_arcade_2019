##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## my make file
##

NAME	=	

SRCS	=	

OBJS	=	

CC		=

RM		=

SNAKE_LIB = ./Snake/

CENTIPEDE_LIB = ./Centipede/

MYLIB = -L $(SNAKE_LIB) -l$(SNAKE_LIB) \
		-L $(CENTIPEDE_LIB) -l$(CENTIPEDE_LIB)

all: 
		@ make -s -C $(SNAKE_LIB)
		@ make -s -C $(CENTIPEDE_LIB)

clean:
		@ make clean -s -C $(SNAKE_LIB)

fclean:	
		@ make fclean -s -C $(SNAKE_LIB)

re: 
		@ make re -s -C $(SNAKE_LIB)

.PHONY: all clean fclean re