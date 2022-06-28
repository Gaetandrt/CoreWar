/*
** EPITECH PROJECT, 2022
** B-CPE-201-MPL-2-1-corewar-romain.very
** File description:
** check_comment_and_name
*/

#include "asm.h"

void check_quotes(char *s)
{
    int nb_quote = 0;

    for (int i = 0; s[i]; i++)
        if (s[i] == '"')
            nb_quote++;
    if (nb_quote != 2)
        print_error("Error: Wrong quotes.\n");
}

char *check_good_name_structure(char *s)
{
    int i = 0;
    char *name = fill_in(my_strlen(s));
    int a = 0;

    for (; s[i] && s[i] == ' ' && s[i] == '\t'; i++);
    for (; s[i] && s[i] != ' '; name[i] = s[i], i++);
    if (my_strncmp(".name", name, 5))
        print_error("Error: Wrong name structure.\n");
    check_quotes(s);
    name = fill_in(128);
    deplace_pointer_to_quote(&s);
    for (; s[a] && s[a] != '"'; name[a] = s[a], a++);
    if (my_strlen(name) > PROG_NAME_LENGTH || name[0] == '\0')
        print_error("Error: Name\n");
    for (a++; s[a]; a++)
        if (s[a] != ' ' && s[a] != '\t' &&
            s[a] != '\n' && s[a] != '#')
            print_error("Error: Wrong name structure.\n");
    return name;
}

void check_name(header_t *header)
{
    int nb = 0;
    size_t len = 0;

    for (int a = 0;
        (nb = getline(&header->prog_name, &len, header->file)) != -1; a = 0) {
        for (; header->prog_name[a] == ' ' && header->prog_name[a]; a++);
        if (header->prog_name[a] == '#' || header->prog_name[a] == '\n')
            continue;
        else if (header->prog_name[a] == '.')
            break;
        else
            print_error("Error: wrong instruction before header.\n");
    }
    if (nb == -1)
        print_error("Error: No name in the name.\n");
    header->prog_name = check_good_name_structure(header->prog_name);
}

char *check_good_comment_structure(char *s)
{
    int i = 0;
    char *comment = fill_in(my_strlen(s));
    int a = 0;

    for (; s[i] && s[i] == ' ' && s[i] == '\t'; i++);
    for (; s[i] && s[i] != ' '; comment[i] = s[i], i++);
    my_strncmp(".comment", comment, 8) ? print_error("Error: comment\n") : 0;
    check_quotes(s);
    comment = fill_in(2048);
    deplace_pointer_to_quote(&s);
    for (; s[a] && s[a] != '"'; comment[a] = s[a], a++);
    my_strlen(comment) > COMMENT_LENGTH ?  print_error("Error:comment\n") : 0;
    comment[0] == '\0' ? print_error("Error: comment too short.\n") : 0;
    for (a++; s[a]; a++)
        if (s[a] != ' ' && s[a] != '\t' && s[a] != '\n' && s[a] != '#')
            print_error("Error: Wrong comment structure.\n");
    return comment;
}

void check_comment(header_t *header)
{
    int nb = 0;
    size_t len = 0;

    for (int a = 0;
        (nb = getline(&header->comment, &len, header->file)) != -1; a = 0) {
        for (; header->comment[a] == ' ' && header->comment[a]; a++);
        if (header->comment[a] == '#' || header->comment[a] == '\n')
            continue;
        else if (header->comment[a] == '.')
            break;
        else
            print_error("Error: wrong instruction before comment.\n");
    }
    if (nb == -1)
        print_error("Error: No commment in the header.\n");
    header->comment = check_good_comment_structure(header->comment);
}
