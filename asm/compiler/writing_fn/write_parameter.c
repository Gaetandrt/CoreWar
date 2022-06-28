/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** write_parameter.c
*/

#include "compiler.h"

static void write_debug_param(char *type, int nbr)
{
    my_putstr("   ");
    my_putstr(type);
    my_put_nbr(nbr);
    my_putchar('\n');
}

static void write_and_fill(int fd, char *param, int size)
{
    int nbr = 0;

    param[0] = '+';
    nbr = my_getnbr(param);
    if (size == DIR_SIZE)
        write_debug_param("Direct:        ", nbr);
    if (size == IND_SIZE)
        write_debug_param("Indirect:      ", nbr);
    write(fd, &nbr, sizeof(nbr));
    free(param);
}

static void write_register(int fd, char *name)
{
    int nbr = 0;

    name[0] = '+';
    nbr = my_getnbr(name);
    write_debug_param("Register:      ", nbr);
    write(fd, &nbr, sizeof(nbr));
    free(name);
}

void write_parameter(int fd, char *parameter, instruction_file_t *data)
{
    if (parameter == NULL || my_strlen(parameter) == 0)
        return;
    switch (parameter[0]) {
        case 'r':
            write_register(fd, my_strdup(parameter));
            break;
        case '%':
            write_and_fill(fd, my_strdump(parameter), DIR_SIZE);
            break;
        default:
            write_and_fill(fd, my_strdump(parameter), IND_SIZE);
            break;
    }
}
