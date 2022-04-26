##
## EPITECH PROJECT, 2021
## LE-MIN
## File description:
## Makefile
##

CC			=	gcc --coverage -g3 -I ../include

RM			= 	rm -f

TARGET		=	unit-tests

SRC			=	$(wildcard *.c)		\
				$(wildcard ../lib/*.c)		\

OBJ			= 	$(SRC:.c=.o)

CFLAGS		= 	-Wall -Wextra

all			:	$(TARGET)
			./$(TARGET)

$(TARGET)	:	$(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ) -lcriterion

clean		:
			$(RM) $(OBJ)

fclean		:	clean
			$(RM) $(TARGET)
			$(RM) $(wildcard *.gcno)
			$(RM) $(wildcard *.gcda)

re			:	fclean all
