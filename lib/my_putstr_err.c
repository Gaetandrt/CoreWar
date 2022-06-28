/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** my_putstr_err.c
*/

#include <unistd.h>
#include <stdlib.h>

int my_strlen(char *str);

void my_putstr_err(char *str, char *arg)
{
    for (int i = 0; str[i]; i++) {
        if (str[i] == '_') {
            write(2, arg, my_strlen(arg));
            continue;
        }
        write(2, &str[i], 1);
    }
    exit(84);
}
