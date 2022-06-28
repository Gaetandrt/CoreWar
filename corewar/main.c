/*
** EPITECH PROJECT, 2022
** B-CPE-201-MPL-2-1-corewar-romain.very
** File description:
** main
*/

#include "corewar.h"

int print_help(void)
{
    my_printf("USAGE\n./corewar [-dump nbr_cycle] [[-n prog_number]"
    "[-a load_address] prog_name] ...\n"
    "DESCRIPTION\n-dump nbr_cycle dumps the memory after the "
    "nbr_cycle execution (if the round isn’t already over) with the "
    "following format: 32 bytes/line in hexadecimal (A0BCDEFE1DD3...)"
    "\n-n prog_number sets the next program’s number. By default, the "
    "first free number in the parameter order\n-a load_address sets the "
    "next program’s loading address. When no address is specified, "
    "optimize the addresses so that the processes are as far away from "
    "each other as possible. The addresses are MEM_SIZE modulo.\n");
    return (0);
}

int main(int argc, char **argv)
{
    champion_t **champions = malloc(sizeof(champion_t *) * (argc - 1));
    virtual_machine_t *vm = malloc(sizeof(virtual_machine_t));
    int i = 1;

    if (argc == 2 && !my_strcmp(argv[1], "-h"))
        return print_help();
    for (; i < argc; i++) {
        printf(".name:%s\n.size:%d\n\n%s\n\n", champions[i - 1]->name, 
        champions[i - 1]->size_script, champions[i - 1]->script);
        champions[i - 1] = get_champion(argv[i]);
    }
    vm->champions = champions;
    vm->cycles = 0;
    vm->nb_champions = argc - 1;
    vm->memory = get_memory(champions, argc - 1);
    vm->nb_process = argc - 1;
    vm->pc = init_pc(vm->nb_champions, vm->champions);
    process_vm(vm);
    return 0;
}


// SI VOUS VOULEZ PRINT LES CHAMPIONS, METTEZ CETTE LIGNE DANS LE FOR
// printf(".name:%s\n.size:%d\n\n%s\n\n", champions[i - 1]->name, 
// champions[i - 1]->size_script, champions[i - 1]->script);
