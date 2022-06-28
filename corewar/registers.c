/*
** EPITECH PROJECT, 2021
** B-CPE-201-MPL-2-1-corewar-romain.very
** File description:
** registers.c
*/

#include "corewar.h"

reg_t **init_register(int id)
{
    reg_t **registers = malloc(sizeof(reg_t *) * REG_NUMBER);
    int i = 0;

    for (i = 0; i < REG_NUMBER; i++) {
        registers[i] = malloc(sizeof(reg_t));
        registers[i]->reg = i + 1;
        registers[i]->value = 0;
    }
    registers[0]->value = id;
    return registers;
}
