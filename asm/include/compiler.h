/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** compiler.h
*/

#ifndef COMPILER
    #define COMPILER

    #include "asm.h"

// Main compiler functions:
void compiler(instruction_file_t *file, header_t *header);

// Compiler tools functions:
int create_hexa_file(char *path_to_file);

// Writing functions (main function for compiler):
bool write_instruction_code(int fd, char *instruction);
void write_coding_byte(int fd, char *param1, char *param2, char *param3);
void write_parameter(int fd, char *parameter, instruction_file_t *data);
void calc_prog_size(instruction_file_t *file, int *prog_size);

#endif/* COMPILER */
