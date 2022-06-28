/*
** EPITECH PROJECT, 2022
** B-CPE-201-MPL-2-1-corewar-romain.very
** File description:
** my_help
*/

#include "asm.h"

int print_help(void)
{
    my_printf("USAGE\n./asm file_name[.s]\n"
    "DESCRIPTION\nfile_name file in assembly language to be converted into "
    "file_name.cor, an executable in the Virtual Machine.\n");
    exit(0);
}
