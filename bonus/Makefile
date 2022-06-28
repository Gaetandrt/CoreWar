##
## EPITECH PROJECT, 2021
## B-CPE-201-MPL-2-1-corewar-romain.very
## File description:
## Makefile
##

CFLAGS	= -W -Wall -Wextra

CPPFLAGS	= -I./include -I../include -I../corewar/include

LDFLAG	=	-lcsfml-graphics -lcsfml-system -lcsfml-audio

SRC	=	$(wildcard src/*.c) \
		$(wildcard ../lib/*.c) \
		$(wildcard ../corewar/*.c) \
		$(wildcard ../corewar/functions/*.c) \

OBJ	=	$(SRC:.c=.o)

BIN	=	bonus

all: $(BIN)

$(BIN): $(OBJ)
	$(CC) $(OBJ) -o $(BIN) $(LDFLAG)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(BIN)

re: fclean all
