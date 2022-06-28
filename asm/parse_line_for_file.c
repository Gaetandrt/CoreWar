/*
** EPITECH PROJECT, 2022
** B-CPE-201-MPL-2-1-corewar-romain.very
** File description:
** parse_line_for_file
*/

#include "asm.h"

char *parse_instruction(char *line_command)
{
    char *instruction = fill_in(my_strlen(line_command));

    for (int i = 0; line_command[i] && line_command[i] != ' '; i++)
        instruction[i] = line_command[i];
    return instruction;
}

char *parse_p1(char *line_command)
{
    char *p1 = fill_in(my_strlen(line_command));
    int i = 0;

    for (; line_command[i] && line_command[i] != ' '; i++);
    for (; line_command[i] && line_command[i] == ' '; i++);
    for (int j = 0; line_command[i] && line_command[i] != ','; i++, j++)
        p1[j] = line_command[i];
    return p1;
}

char *parse_p2(char *line_command, char *instruction)
{
    char *p2 = fill_in(my_strlen(line_command));
    int i = 0;

    for (; line_command[i] && line_command[i] != ' '; i++);
    for (; line_command[i] && line_command[i] == ' '; i++);
    for (; line_command[i] && line_command[i] != ','; i++);
    line_command[i] == ',' ? i++ : 0;
    for (; line_command[i] && line_command[i] == ' '; i++);
    for (int j = 0; line_command[i] && line_command[i] != ',';)
        p2[j++] = line_command[i++];
    return p2;
}

char *parse_p3(char *line_command, char *instruction)
{
    char *p3 = fill_in(my_strlen(line_command));
    int i = 0;

    for (; line_command[i] && line_command[i] != ' '; i++);
    for (; line_command[i] && line_command[i] == ' '; i++);
    for (; line_command[i] && line_command[i] != ','; i++);
    line_command[i] == ',' ? i++ : 0;
    for (; line_command[i] && line_command[i] == ' '; i++);
    for (; line_command[i] && line_command[i] != ','; i++);
    line_command[i] == ',' ? i++ : 0;
    for (; line_command[i] && line_command[i] == ' '; i++);
    for (int j = 0; line_command[i] && line_command[i] != ' ';)
        p3[j++] = line_command[i++];
    return p3;
}
