/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** create_hexa_file.c
*/

#include "compiler.h"

static char *edit_file_name(char *file)
{
    int i = 0;
    char *new_file = fill_in(my_strlen(file) + 2);

    for (; file[i]; i++);
    for (; i >= 0 && file[i] != '/'; i--);
    i++;
    for (int a = 0; file[i] != '.'; i++)
        new_file[a++] = file[i];
    my_strcat(new_file, ".cor");
    free(file);
    return (new_file);
}

int create_hexa_file(char *path_to_file)
{
    char *file_name = NULL;
    int fd = 0;

    file_name = edit_file_name(my_strdump(path_to_file));
    fd = open(file_name, O_RDWR | O_CREAT, 0644);
    if (fd == -1)
        print_error("Error: Can't create the file\n");
    return fd;
}
