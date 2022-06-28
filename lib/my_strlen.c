/*
** EPITECH PROJECT, 2022
** Make_fast
** File description:
** my_strlen
*/

#include "../include/my.h"

int my_strlen(char *str)
{
    int i = 0;

    if (!str)
        return (0);
    for (; str[i]; i++);
    return i;
}

void print_error(char *str)
{
    my_putstr(str);
    exit(84);
}
