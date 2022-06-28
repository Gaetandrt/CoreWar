/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** compiler.c
*/

#include "compiler.h"

long long int little_to_big_endian(long long int x)
{
    return ((x & 0x000000FF) << 24) | ((x & 0x0000FF00) << 8) |
        ((x & 0x00FF0000) >> 8) | ((x & 0xFF000000) >> 24);
}

void write_magic_number(header_t *header, int fd)
{
    int magic_number = little_to_big_endian(COREWAR_EXEC_MAGIC);

    write(fd, &magic_number, sizeof(int));
}

void write_prog_name(header_t *header, int fd, int prog_size)
{
    int prog_size_endian = little_to_big_endian(prog_size);

    write(fd, header->prog_name, 128);
    write(fd, "\0\0\0\0", 4);
    write(fd, &prog_size_endian, sizeof(int));
    write(fd, header->comment, 2048);
    write(fd, "\0\0\0\0", 4);
}

void compiler(instruction_file_t *file, header_t *header)
{
    int fd_cor = create_hexa_file(header->filepath);
    int prog_size = 0;

    calc_prog_size(file, &prog_size);
    write_magic_number(header, fd_cor);
    write_prog_name(header, fd_cor, prog_size);
    for (instruction_file_t *data = file; data; data = data->next) {
        if (write_instruction_code(fd_cor, data->instruction))
            write_coding_byte(\
            fd_cor, data->parametre1, data->parametre2, data->parametre3);
        write_parameter(fd_cor, data->parametre1, data);
        write_parameter(fd_cor, data->parametre2, data);
        write_parameter(fd_cor, data->parametre3, data);
    }
}
