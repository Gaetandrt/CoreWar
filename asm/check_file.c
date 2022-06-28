/*
** EPITECH PROJECT, 2022
** B-CPE-201-MPL-2-1-corewar-romain.very
** File description:
** check_file
*/

#include "asm.h"

void deplace_pointer_to_quote(char **line_of_name)
{
    for (int i = 0; (*line_of_name)[i]; i++)
        if ((*line_of_name)[i] == '"') {
            (*line_of_name) += i + 1;
            return;
        }
}

void check_extension_file(char *filepath)
{
    int i = 0;

    for (; filepath[i]; i++);
    for (i -= 1; filepath[i] != '.'; i--);
    if (!(filepath[i] == '.' && filepath[i + 1] == 's'))
        print_error("Error: Wrong file extension.\n");
}

void check_error_in_file(header_t *header, char *filepath)
{
    check_extension_file(filepath);
    check_name(header);
    check_comment(header);
}

void check_file(char *filepath, header_t *header)
{
    header->file = fopen(filepath, "r");

    if (header->file == NULL) {
        my_printf("Error: Can't open file %s\n", filepath);
        exit(84);
    }
    header->filepath = my_strdup(filepath);
    check_error_in_file(header, filepath);
}

