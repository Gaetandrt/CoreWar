/*
** EPITECH PROJECT, 2021
** B-CPE-201-MPL-2-1-corewar-romain.very
** File description:
** get_text.c
*/

#include "corewar.h"

char *get_memory(champion_t **champions, int nb_champs)
{
    char *text = malloc(sizeof(char) * (MEM_SIZE * 2));
    int between = MEM_SIZE * 2;
    int i = 0;
    int j = 0;
    int ind = 0;

    for (; i < nb_champs; i++)
        between -= champions[i]->size_script * 2;
    for (i = 0; i < nb_champs; i++) {
        for (j = 0; champions[i]->script[j] != '\0'; j++, ind++)
            text[ind] = champions[i]->script[j];
        for (j = 0; j < between / nb_champs; j++, ind++)
            text[ind] = '0';
    }
    return text;
}
