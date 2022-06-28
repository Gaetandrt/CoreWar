/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** binary_write_editing.c
*/

#include "../include/my.h"

void binary_write_nbr_in_file(int fd, int nbr)
{
    write(fd, &nbr, sizeof(nbr));
}

void binary_write_str_in_file(int fd, char *str)
{
    int bin_value = 0;

    for (int i = 0; str[i]; i++) {
        for (int j = 7; j >= 0; --j) {
            bin_value = str[i] & (1 << j) ? 1 : 0;
            binary_write_nbr_in_file(fd, bin_value);
        }
    }
}
