/*
** EPITECH PROJECT, 2022
** Makedossier
** File description:
** my
*/

#ifndef MY_H_
    #define MY_H_

    #include <stdarg.h>
    #include <stdio.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <unistd.h>
    #include <assert.h>
    #include <string.h>
    #include <dirent.h>
    #include <stdlib.h>
    #include <pwd.h>
    #include <time.h>
    #include <errno.h>
    #include <ncurses.h>
    #include <fcntl.h>
    #include <signal.h>

void my_printf(char *str, ...);
void my_rev_str(char **str);
void my_putchar(char c);
void my_putstr(char *str);
void my_put_nbr(int nb);
int my_getnbr(char const *str);
int my_strlen(char *str);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strcpy(char *dest, char const *src);
char *my_strdump(char *str);
char *my_strncpy(char *dest , char const *src, int n);
char *my_strcat(char *dest, char const *str);
char *my_strncat(char *dest , char const *src , int nb);
char *fill_in(int size);
char *destroy_string(char *str);
void binary_write_nbr_in_file(int fd, int nbr);
void binary_write_str_in_file(int fd, char *str);
char *nbr_to_hexa(int nbr);
int hexa_to_nbr(char *hexa);
char *nbr_decimal_to_str_binary(int nbr);
int str_binary_to_nbr_decimal(char *str);
char *my_strdup(char *str);
void my_putstr_err(char *str, char *arg);

char **alloc_2d_array(int size_row, int size_cols);

#endif /* !MY_H_ */
