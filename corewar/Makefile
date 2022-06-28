##
## EPITECH PROJECT, 2021
## B-CPE-201-MPL-2-1-corewar-romain.very
## File description:
## Makefile
##

CFLAGS  = -W -Wall -Wextra -Wno-unused

CPPFLAGS = -I../include/ -I./include/

SRC	=	$(wildcard *.c) \
		$(wildcard ../lib/*.c) \
		$(wildcard functions/*.c)

OBJ =  $(SRC:.c=.o)

BIN	=	corewar

.SILENT: $(OBJ)

all: $(BIN)

$(BIN): $(OBJ)
	@$(CC) $(OBJ) -o $(BIN)

clean:
	@$(RM) $(OBJ)

fclean : clean
	@$(RM) $(BIN)

re: fclean all
