/*
** EPITECH PROJECT, 2021
** Epitech-C-template
** File description:
** my_getnbr.c
*/

int my_getnbr(char const *str)
{
    int result = 0;
    int sign = 1;

    while (*str == '-' || *str == '+')
        if (*str++ == '-')
            sign = -sign;
    for (int i = 0; str[i]; i++) {
        if ('0' <= str[i] && str[i] <= '9') {
            result *= 10;
            result += str[i] - '0';
        } else
            break;
    }
    return result * sign;
}
