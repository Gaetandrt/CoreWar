/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** my_strdump.c
*/

#include <stdlib.h>
#include <unistd.h>

static int get_size(char *str)
{
    int result = 0;

    while (str[result] != '\0') {
        result += 1;
    }
    return result;
}

char *my_strdump(char *str)
{
    char *result = NULL;
    int size = 0;

    size = get_size(str);
    if (size == 0)
        return NULL;
    result = malloc(sizeof(char) * (size + 1));
    if (result == NULL) {
        write(2, "ERROR: bad malloc\n", 19);
        exit(84);
    }
    for (int i = 0; str[i]; i++)
        result[i] = str[i];
    result[size] = '\0';
    return result;
}
