/*
** EPITECH PROJECT, 2022
** B-CPE-201-MPL-2-1-corewar-romain.very
** File description:
** parse_file
*/

#include "asm.h"

void check_error_instruction_and_parametre(char *instru, char *p1,
char *p2, char *p3)
{
    if (!my_strcmp(instru, "live") || !my_strcmp(instru, "zjmp")
        || !my_strcmp(instru, "fork") || !my_strcmp(instru, "lfork")
        || !my_strcmp(instru, "aff"))
        p1[0] == '\0' || p2[0] != '\0' || p3[0] != '\0' ?
        my_printf("Error: %s instruction"
        " need 1 parametre\n", instru), print_error("") : 0;
    if (!my_strcmp(instru, "ld") || !my_strcmp(instru, "st")
        || !my_strcmp(instru, "lld"))
        p2[0] == '\0' || p3[0] != '\0' ? my_printf("Error: "
        "%s instruction need 2 parametres\n", instru),
        print_error("") : 0;
    if (!my_strcmp(instru, "add") || !my_strcmp(instru, "sub")
        || !my_strcmp(instru, "and") || !my_strcmp(instru, "or")
        || !my_strcmp(instru, "xor") || !my_strcmp(instru, "ldi")
        || !my_strcmp(instru, "sti") || !my_strcmp(instru, "lldi"))
        p2[0] == '\0' || p3[0] == '\0' || p1[0] == '\0' ? my_printf(
        "Error: %s instruction 3 parametres\n", instru),
        print_error("") : 0;
}

instruction_file_t *parse_file(header_t *header)
{
    instruction_file_t *file_pr = NULL;
    char *instruction = NULL;
    char *p1 = NULL;
    char *p2 = NULL;
    char *p3 = NULL;

    for (int i = 0; header->file_contained[i++];) {
        if (!header->file_contained[i])
            break;
        instruction = parse_instruction(header->file_contained[i]);
        p1 = parse_p1(header->file_contained[i]);
        p2 = parse_p2(header->file_contained[i], instruction);
        p3 = parse_p3(header->file_contained[i], instruction);
        check_error_instruction_and_parametre(instruction, p1, p2, p3);
        push_node_at_back(&file_pr, (char *[4]){instruction, p1, p2, p3});
        free(instruction);
        free(p1);
        free(p2);
    }
    return file_pr;
}
