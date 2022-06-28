/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** write_coding_byte.c
*/

#include "compiler.h"

static void write_debug_coding_byte(int nbr, char *str)
{
    my_putstr("   Coding byte:   ");
    my_put_nbr(nbr);
    my_putstr(" (");
    my_putstr(str);
    my_putstr(")\n");
}

static int add_weight(char *param)
{
    int result = -1;

    switch (param[0]) {
        case 'r':
            result = 1;
            break;
        case '%':
            result = 10;
            break;
        default:
            result = 11;
            break;
    }
    return result;
}

void write_coding_byte(int fd, char *param1, char *param2, char *param3)
{
    char *result = my_strdump("00000000\0");
    int coding_byte = 0;

    if (param1 != NULL && my_strlen(param1) != 0) {
        result[0] = add_weight(param1) / 10 + '0';
        result[1] = add_weight(param1) % 10 + '0';
    }
    if (param2 != NULL && my_strlen(param2) != 0) {
        result[2] = add_weight(param2) / 10 + '0';
        result[3] = add_weight(param2) % 10 + '0';
    }
    if (param3 != NULL && my_strlen(param3) != 0) {
        result[4] = add_weight(param3) / 10 + '0';
        result[5] = add_weight(param3) % 10 + '0';
    }
    coding_byte = str_binary_to_nbr_decimal(result);
    write_debug_coding_byte(coding_byte, result);
    write(fd, &coding_byte, 1);
}
