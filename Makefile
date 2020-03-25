##
## EPITECH PROJECT, 2020
## Arcade
## File description:
## Makefile root
##

NAME	=	arcade

all: $(NAME) 

$(NAME): core games graphicals

core:
	make -C ./core all

games:
	make -C ./games all

graphicals:
	make -C ./lib all

clean:
	make -C ./core clean
	make -C ./games clean
	make -C ./lib clean

fclean:
	make -C ./core fclean
	make -C ./games fclean
	make -C ./lib fclean

re: fclean all

.PHONY: clean fclean re core games graphicals