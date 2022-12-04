##
## EPITECH PROJECT, 2022
## B-CPE-101-NCY-1-1-myprintf-guillaume.michel
## File description:
## Makefile
##

CFLAGS	=	-W -Wall -Wextra -g2
LDFLAGS	=	-l csfml-graphics -l csfml-audio -l csfml-system -l csfml-window

SRC     =       $(wildcard src/*.c)

OBJ     =		$(SRC:.c=.o)

NAME    =		my_hunter

all:	$(NAME)

$(NAME):		$(OBJ)
		gcc -o $(NAME) src/*.c -s $(LDFLAGS)
		make clean

clean:
		rm -f $(OBJ)

fclean:			clean
		rm -f *.log
		rm -f $(NAME)

re:		fclean all
