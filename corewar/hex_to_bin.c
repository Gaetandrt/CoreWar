/*
** EPITECH PROJECT, 2021
** B-CPE-201-MPL-2-1-corewar-romain.very
** File description:
** hex_to_bin.c
*/

#include "corewar.h"

void int_to_bin(int nb, int *bin)
{
    int i = 0;

    for (i = 0; nb > 0; i++) {
        bin[i] = nb % 2;
        nb /= 2;
    }
}

int *hexa_to_bin(char *hex)
{
    int *bin = malloc(sizeof(int) * 8);
    int *bin_rev = malloc(sizeof(int) * 8);
    int nb = hexa_to_nbr(hex);

    int_to_bin(nb, bin);
    for (int i = 0; i < 8; i++)
        bin_rev[i] = bin[7 - i];
    free(bin);
    return bin_rev;
}
