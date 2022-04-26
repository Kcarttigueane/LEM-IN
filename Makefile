##
## EPITECH PROJECT, 2021
## LE-MIN
## File description:
## Makefile
##

RM	= rm -f

NAME	= lem_in

SRC	=	$(wildcard *.c)	\
		$(wildcard lib/*.c) \
		$(wildcard sources/*.c) \
		$(wildcard sources/linked_list/*.c) \
		$(wildcard sources/debug_functions/*.c) \
		$(wildcard sources/parsing/*.c) \
		$(wildcard sources/free_functions/*.c) \
		$(wildcard sources/queue_functions/*.c) \
		$(wildcard sources/path_finding/*.c) \

OBJ	= $(SRC:.c=.o)

CFLAGS	+= -Wall -Wextra -I include -g3

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)
	$(RM) $(wildcard lib/*.gcno)
	$(RM) $(wildcard lib/*.gcda)
	$(RM) $(wildcard tests/*.gcno)
	$(RM) $(wildcard tests/*.gcda)
	$(RM) $(wildcard vgcore*)
	make -C tests fclean

re:	fclean all

tests_run:
	make -C tests all

.PHONY: all clean fclean re tests_run
