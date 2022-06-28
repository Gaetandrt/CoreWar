/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** my_rev_str.c
*/

#include "../include/my.h"

void my_rev_str(char **str)
{
    int size = my_strlen((*str));
    char *tmp = fill_in(size--);

    for (int i = 0; size > -1; tmp[i++] = (*str)[size--]);
    (*str) = my_strdup(tmp);
}
