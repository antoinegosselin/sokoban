##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

SRC	=	src/main.c \
		src/my_len.c \
		src/read_functions.c \
		src/my_put_map.c \
		src/check_malloc.c \
		src/fill_board.c \
		src/move.c \
		src/usage.c \
		src/init.c \
		src/zero.c \
		src/loose.c

NAME	=	my_sokoban

OBJ	=	$(SRC:.c=.o)

LIB_PATH	=	./lib/my/

LIB_NAME	=	my

TEST_PATH 	= 	./tests/

CFLAGS	=	-W -Wall -I include/ -lncurses

all:	$(NAME) clean

$(NAME):	$(OBJ)
	make -C ./lib/my/
	gcc -o $(NAME) $(OBJ) -L$(LIB_PATH) -l$(LIB_NAME) $(CFLAGS)

clean:
	make clean -C ./lib/my/
	rm -f $(OBJ)
	rm -f *.gc*

fclean:	clean
	rm -f $(NAME)
	rm -f $(LIB_PATH)libmy.a
	rm -f unit_test*

re:	fclean all

tests_run: 
	