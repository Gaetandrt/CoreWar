/*
** EPITECH PROJECT, 2022
** B-CPE-201-MPL-2-1-corewar-romain.very
** File description:
** push_node
*/

#include "asm.h"

void push_node_at_back(instruction_file_t **my_struct, char **parametres)
{
    instruction_file_t *new_node = malloc(sizeof(instruction_file_t));
    instruction_file_t *tmp = (*my_struct);

    new_node->instruction = my_strdup(parametres[0]);
    new_node->parametre1 = my_strdup(parametres[1]);
    new_node->parametre2 = my_strdup(parametres[2]);
    new_node->parametre3 = my_strdup(parametres[3]);
    new_node->next = NULL;
    if ((*my_struct) == NULL)
        (*my_struct) = new_node;
    else {
        for (; tmp->next != NULL; tmp = tmp->next);
        tmp->next = new_node;
    }
}
