/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** write_instruction_code.c
*/

#include "compiler.h"

static void write_debug_code(char nbr, char *str)
{
    static int i = 1;

    my_putchar('\n');
    my_put_nbr(i++);
    my_putstr(".\n   Instruction:   ");
    my_put_nbr(nbr);
    my_putstr(" (");
    my_putstr(str);
    my_putstr(")\n");
}

bool write_instruction_code(int fd, char *instruction)
{
    char *ignored_instructions[5] = {"live", "zjmp", "fork", "lfork", NULL};
    bool is_label = true;

    for (int i = 0; op_tab[i].mnemonique != 0; i++) {
        if (my_strcmp(op_tab[i].mnemonique, instruction))
            continue;
        write_debug_code(op_tab[i].code, op_tab[i].mnemonique);
        write(fd, &op_tab[i].code, sizeof(op_tab[i].code));
        is_label = false;
        break;
    }
    if (is_label)
        return false;
    for (int i = 0; ignored_instructions[i] != NULL; i++)
        if (!my_strcmp(instruction, ignored_instructions[i]))
            return false;
    return true;
}
