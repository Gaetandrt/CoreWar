/*
** EPITECH PROJECT, 2022
** B-CPE-201-MPL-2-1-corewar-romain.very
** File description:
** main
*/

#include "asm.h"

void compiler(instruction_file_t *file, header_t *header);

void check_error(int argc, char **argv, header_t *header)
{
    if (argc != 2 || (argc == 2 && !my_strcmp(argv[1], "-h")))
        print_help();
    check_file(argv[1], header);
    remove_comment(header);
}

int main(int argc, char **argv)
{
    header_t *header = init_struct();
    instruction_file_t *instruction_file = NULL;

    check_error(argc, argv, header);
    instruction_file = parse_file(header);
    compiler(instruction_file, header);
    return (0);
}
