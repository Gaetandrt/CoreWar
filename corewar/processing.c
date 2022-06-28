/*
** EPITECH PROJECT, 2021
** B-CPE-201-MPL-2-1-corewar-romain.very
** File description:
** precessing.c
*/

#include "corewar.h"

void process_pc(process_t *pc, virtual_machine_t *vm)
{
    char *fct = detect_func(vm->memory, pc->coord_pc);
    return;
}
