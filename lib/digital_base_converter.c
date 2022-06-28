/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** digital_base_converter.c
*/

#include "../include/my.h"

int hexa_to_nbr(char *hexa)
{
    int nbr = 0;
    char c = 0;

    while (*hexa) {
        c = *hexa;
        if (c >= '0' && c <= '9')
            nbr = nbr * 16 + c - '0';
        else if (c >= 'A' && c <= 'F')
            nbr = nbr * 16 + c - 'A' + 10;
        hexa++;
    }
    return (nbr);
}

char *nbr_to_hexa(int nbr)
{
    int quotient = nbr;
    int remainder;
    char *result = malloc(sizeof(char) * 101);

    for (int i = 0; i < 101; i++)
        result[i] = '\0';
    for (int i = 0; quotient != 0; i++) {
        remainder = quotient % 16;
        if (remainder < 10)
            result[i] = 48 + remainder;
        else
            result[i] = 55 + remainder;
        quotient /= 16;
    }
    for (int i = 0; result[i]; i++)
        if ('A' <= result[i] && result[i] <= 'Z')
            result[i] += 32;
    return result;
}

static int calc_unit(int pow)
{
    int result = 2;
    int save = result;

    for (int i = pow; i > 1; i--)
        result *= save;
    return result;
}

int str_binary_to_nbr_decimal(char *str)
{
    int result = 0;
    int unit = 0;
    int pow = my_strlen(str) - 1;

    for (int i = 0; str[i]; i++) {
        unit = 0;
        if (str[i] == '1')
            unit = calc_unit(pow);
        pow -= 1;
        result += unit;
    }
    return result;
}

char *nbr_decimal_to_str_binary(int nbr)
{
    int size = 1;
    char *result;

    for (int i = nbr; i / 2; i /= 2)
        size++;
    result = malloc(sizeof(char) * (size + 1));
    for (int i = 0; i < size; i++) {
        result[i] = nbr % 2 ? '1' : '0';
        nbr /= 2;
    }
    result[size] = '\0';
    my_rev_str(&result);
    return result;
}
