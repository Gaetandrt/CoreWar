/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** calc_prog_size.c
*/

#include "compiler.h"

static int calc_param_size(char *param)
{
    int result = 0;

    if (param == NULL || my_strlen(param) == 0)
        return result;
    if (param[0] == 'r')
        result += 1;
    if (param[0] == '%')
        result += 1;
    else
        result += 1;
    return result;
}

static int calc_line_size(char *inst, char *param1, char *param2, char *param3)
{
    int result = 0;
    bool calp = true;

    for (int i = 0; op_tab[i].mnemonique != 0; i++) {
        if (!my_strcmp(op_tab[i].mnemonique, inst)) {
            result += 1;
            calp = false;
        }
    }
    if (calp)
        result += 1;
    result += calc_param_size(param1);
    result += calc_param_size(param2);
    result += calc_param_size(param3);
    return result;
}

void calc_prog_size(instruction_file_t *file, int *prog_size)
{
    int unit = 0;
    int count = 1;

    for (instruction_file_t *data = file; data; data = data->next) {
        unit = calc_line_size(data->instruction, \
        data->parametre1, data->parametre2, data->parametre3);
        *prog_size += unit;
    }
}
