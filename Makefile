##
## EPITECH PROJECT, 2021
## Makefile Corewar
## File description:
## Makefile
##

all:
	@make -C asm/ --no-print-directory
	@make -C corewar/ --no-print-directory

clean:
	make clean -C asm/ --no-print-directory
	make clean -C corewar/ --no-print-directory

fclean:
	make fclean -C asm/ --no-print-directory
	make fclean -C corewar/ --no-print-directory
	make fclean -C bonus/ --no-print-directory

bonus:
	@make -C bonus/ --no-print-directory

only_asm:
	@make -C asm/ --no-print-directory

only_corewar:
	@make -C corewar/ --no-print-directory

re:    fclean all
