/*
** EPITECH PROJECT, 2022
** B-CPE-201-MPL-2-1-corewar-romain.very
** File description:
** init_all_instances
*/

#include "asm.h"

header_t *init_struct(void)
{
    header_t *header = malloc(sizeof(header_t));

    header->prog_name = NULL;
    header->comment = NULL;
    header->magic = COREWAR_EXEC_MAGIC;
    header->prog_size = 0;
    header->file = NULL;
    header->file_contained = NULL;
    header->filepath = NULL;
    return header;
}
