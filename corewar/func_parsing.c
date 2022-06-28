/*
** EPITECH PROJECT, 2022
** parse function name and execute the right function
** File description:
** func_parsing
*/

#include "corewar.h"

int func_parse_1(char *func, char *args)
{
    if (my_strcmp(func, "ldi") == 0)
        return (ldi(args));
    if (my_strcmp(func, "sti") == 0)
        return (sti(args));
    if (my_strcmp(func, "fork") == 0)
        return (my_fork(args));
    if (my_strcmp(func, "lld") == 0)
        return (lld(args));
    if (my_strcmp(func, "lldi") == 0)
        return (lldi(args));
    if (my_strcmp(func, "lfork") == 0)
        return (my_lfork(args));
    if (my_strcmp(func, "aff") == 0)
        return (aff(args));
    return (0);
}

int func_parse(char *func, char *args)
{
    if (my_strcmp(func, "live") == 0)
        return (live(args));
    if (my_strcmp(func, "ld") == 0)
        return (ld(args));
    if (my_strcmp(func, "st") == 0)
        return (st(args));
    if (my_strcmp(func, "add") == 0)
        return (add(args));
    if (my_strcmp(func, "sub") == 0)
        return (sub(args));
    if (my_strcmp(func, "and") == 0)
        return (and(args));
    if (my_strcmp(func, "or") == 0)
        return (or(args));
    if (my_strcmp(func, "xor") == 0)
        return (xor(args));
    if (my_strcmp(func, "zjmp") == 0)
        return (zjmp(args));
    return (func_parse_1(func, args));
}
