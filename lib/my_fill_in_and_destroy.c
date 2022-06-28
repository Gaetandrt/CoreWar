/*
** EPITECH PROJECT, 2022
** Make_fast
** File description:
** my_fill_in_and_destroy
*/

#include "../include/my.h"

char **alloc_2d_array(int size_row, int size_cols)
{
    char **array = malloc(sizeof(char *) * (size_row + 1));
    int i = 0;

    for (; i < size_row; i++)
        array[i] = fill_in(size_cols);
    array[size_row] = NULL;
    return (array);
}

char *fill_in(int size)
{
    char *str = malloc(size + 1);

    for (int i = 0; i <= size; i++)
        str[i] = '\0';
    return str;
}

char *my_strdup(char *str)
{
    char *new_str = fill_in(my_strlen(str));

    if (!str)
        return new_str;
    for (int i = 0; str[i]; i++)
        new_str[i] = str[i];
    return new_str;
}

char *destroy_string(char *str)
{
    for (int i = 0; str[i]; i++)
        str[i] = '\0';
    return str;
}
