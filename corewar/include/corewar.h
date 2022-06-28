/*
** EPITECH PROJECT, 2022
** B-CPE-201-MPL-2-1-corewar-romain.very
** File description:
** corewar
*/

#ifndef COREWAR_H_
    #define COREWAR_H_
    #include "my.h"
    #include "op.h"

int live(char *args);
int ld(char *args);
int st(char *args);
int add(char *args);
int sub(char *args);
int and(char *args);
int or(char *args);
int xor(char *args);
int zjmp(char *args);
int ldi(char *args);
int sti(char *args);
int my_fork(char *args);
int lld(char *args);
int lldi(char *args);
int my_lfork(char *args);
int aff(char *args);

typedef struct function_s {
    int mnemonic;
    int (*fct)(char *);
    // int b_size;
} function_t;

static function_t functions[] = {
    {1, &live},
    {2, &ld},
    {3, &st},
    {4, &add},
    {5, &sub},
    {6, &and},
    {7, &or},
    {8, &xor},
    {9, &zjmp},
    {10, &ldi},
    {11, &sti},
    {12, &my_fork},
    {13, &lld},
    {14, &lldi},
    {15, &my_lfork},
    {16, &aff},
    {0, NULL}
};

typedef struct live_id {
    int value;
    struct live_id *next;
} live_id_t;

typedef struct reg_s {
    int reg;
    int value;
} reg_t;

typedef struct champion_s {
    char *name;
    char *script;
    long int id;
    int size_script;
    reg_t **registers;
    int last_live;
    struct live_id *live_id;
} champion_t;

typedef struct process_s {
    int coord_pc;
    int last_live;
} process_t;

typedef struct virtual_machine_s {
    champion_t **champions;
    int nb_champions;
    char *memory;
    int cycles;
    int nb_process;
    process_t **pc;
} virtual_machine_t;

champion_t *get_champion(char *filepath);
char *get_memory(champion_t **champions, int nb_champs);
process_t **init_pc(int nb_champions, champion_t **champ);
reg_t **init_register(int id);

// Engine.c functions

int process_vm(virtual_machine_t *vm);
void process_pc(process_t *pc, virtual_machine_t *vm);

char *get_cell(char *script, char *func, int i);
char *detect_func(char *script, int i);
int get_args_size(char *func, int i);
int func_parse(char *func, char *args);
int *hexa_to_bin(char *hex);

int is_end(champion_t **champions);

#endif /* !COREWAR_H_ */
