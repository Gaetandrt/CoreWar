/*
** EPITECH PROJECT, 2022
** B-CPE-201-MPL-2-1-corewar-romain.very
** File description:
** parse_file
*/

#include "asm.h"

int st_size_file(char* filepath)
{
    char *str = NULL;
    int nb_n = 0;
    struct stat sb;

    stat(filepath, &sb);
    str = fill_in(sb.st_size);
    read(open(filepath, O_RDONLY), str, sb.st_size);
    for (int i = 0; str[i]; i++)
        if (str[i] == '\n')
            nb_n++;
    return nb_n - 2;
}

char *remove_comment_string(char *str)
{
    char *new_str = fill_in(my_strlen(str));
    int a = 0;
    int i = 0;

    for (; str[a] && (str[a] == ' ' || str[a] == '\t'); a++);
    for (; str[a]; a++) {
        if (str[a] == '#')
            break;
        else
            new_str[i++] = str[a];
    }
    if (str[a] == '\0' && str[a - 1] == '\n')
        new_str[--i] = '\0';
    return new_str;
}

void remove_comment(header_t *header)
{
    header->file_contained = alloc_2d_array(st_size_file(header->filepath), 0);
    char *my_str = NULL;
    size_t len = 0;

    for (int i = 0; getline(&my_str, &len, header->file) != -1; i++)  {
        header->file_contained[i] = remove_comment_string(my_str);
        if (header->file_contained[i][0] == '\n'
            || header->file_contained[i][0] == '\0')
            i--;
    }
    free(my_str);
}
