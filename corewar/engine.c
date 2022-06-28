/*
** EPITECH PROJECT, 2022
** file with the engine of the vm
** File description:
** engine
*/

#include "corewar.h"

int engine_init(char *script, int i)
{
    char *func = NULL;
    char *args = NULL;

    while (1) {
        func = detect_func(script, i);
        args = get_cell(script, func, i);
        i += get_args_size(func, i) * 2;
        func_parse(func, args);
    }
}

int process_vm(virtual_machine_t *vm)
{
    int ind = 0;

    while (!is_end(vm->champions)) {
        vm->cycles++;
        for (ind = 0; ind < vm->nb_champions; ind++)
            vm->champions[ind]->last_live++;
        for (ind = 0; ind < vm->nb_process; ind++)
            process_pc(vm->pc[ind], vm);
    }
    return 0;
}
