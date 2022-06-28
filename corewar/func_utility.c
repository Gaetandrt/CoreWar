/*
** EPITECH PROJECT, 2022
** utility function to get function info
** File description:
** func_utility
*/

#include "corewar.h"

char *get_cell(char *script, char *func, int i)
{
    int args_size = get_args_size(func, i) * 2;
    char *args = malloc(sizeof(char) * args_size + 1);

    for (int j = 0; j < args_size; j++)
        args[j] = script[i + j];
    args[args_size] = '\0';
    return (args);
}

char *detect_func_1(char *func)
{
    if (my_strcmp(func, "08") == 0)
        return ("xor");
    if (my_strcmp(func, "09") == 0)
        return ("zjmp");
    if (my_strcmp(func, "0A") == 0)
        return ("ldi");
    if (my_strcmp(func, "0B") == 0)
        return ("sti");
    if (my_strcmp(func, "0C") == 0)
        return ("fork");
    if (my_strcmp(func, "0D") == 0)
        return ("lld");
    if (my_strcmp(func, "0E") == 0)
        return ("lldi");
    if (my_strcmp(func, "0F") == 0)
        return ("lfork");
    if (my_strcmp(func, "10") == 0)
        return ("aff");
    return (NULL);
}

char *detect_func(char *script, int i)
{
    char *func = malloc(sizeof(char) * 3);
    func[0] = script[i];
    func[1] = script[i + 1];
    func[2] = '\0';

    if (my_strcmp(func, "01") == 0)
        return ("live");
    if (my_strcmp(func, "02") == 0)
        return ("ld");
    if (my_strcmp(func, "03") == 0)
        return ("st");
    if (my_strcmp(func, "04") == 0)
        return ("add");
    if (my_strcmp(func, "05") == 0)
        return ("sub");
    if (my_strcmp(func, "06") == 0)
        return ("and");
    if (my_strcmp(func, "07") == 0)
        return ("or");
    return (detect_func_1(func));
}

int get_args_size_1(char *func, int i)
{
    if (my_strcmp(func, "ldi") == 0)
        return (6);
    if (my_strcmp(func, "sti") == 0)
        return (5);
    if (my_strcmp(func, "fork") == 0)
        return (3);
    if (my_strcmp(func, "lld") == 0)
        return (7);
    if (my_strcmp(func, "lldi") == 0)
        return (6);
    if (my_strcmp(func, "lfork") == 0)
        return (3);
    if (my_strcmp(func, "aff") == 0)
        return (3);
    return (0);
}

int get_args_size(char *func, int i)
{
    if (my_strcmp(func, "live") == 0)
        return (5);
    if (my_strcmp(func, "ld") == 0)
        return (7);
    if (my_strcmp(func, "st") == 0)
        return (5);
    if (my_strcmp(func, "add") == 0)
        return (5);
    if (my_strcmp(func, "sub") == 0)
        return (5);
    if (my_strcmp(func, "and") == 0)
        return (5);
    if (my_strcmp(func, "or") == 0)
        return (5);
    if (my_strcmp(func, "xor") == 0)
        return (5);
    if (my_strcmp(func, "zjmp") == 0)
        return (3);
    return (get_args_size_1(func, i));
}

