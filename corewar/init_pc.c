/*
** EPITECH PROJECT, 2021
** B-CPE-201-MPL-2-1-corewar-romain.very
** File description:
** init_pc.c
*/

#include "corewar.h"

int get_coord(champion_t **champions, int i)
{
    int between = MEM_SIZE * 2;
    int j = 0;
    int ind = 0;

    for (; champions[j]; j++)
        between -= champions[j]->size_script * 2;
    between = between / j;
    for (j = 0; j < i; j++) {
        ind += champions[j]->size_script * 2;
        ind += between;
    }
    return ind;
}

process_t **init_pc(int nb_champions, champion_t **champ)
{
    process_t **pc = malloc(sizeof(process_t *) * nb_champions);

    int i = 0;

    for (; i < nb_champions; i++) {
        pc[i] = malloc(sizeof(process_t));
        pc[i]->coord_pc = get_coord(champ, i);
    }
    return pc;
}
