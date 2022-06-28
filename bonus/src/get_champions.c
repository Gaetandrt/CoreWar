/*
** EPITECH PROJECT, 2021
** B-CPE-201-MPL-2-1-corewar-romain.very
** File description:
** open_file.c
*/

#include "corewar.h"

void int_to_hex(int nb, char *script, int index)
{
    char *base = "0123456789ABCDEF";
    if (nb / 16 != 0) {
        int_to_hex(nb / 16, script, index);
        index++;
    }
    script[index] = base[nb % 16];
}

char *get_name(int fd)
{
    int i = 0;
    int int_name = 0;
    char *name = malloc(sizeof(char) * PROG_NAME_LENGTH);
    char *description = malloc(sizeof(char) * COMMENT_LENGTH + 16);

    read(fd, &int_name, 4);
    for (; i < PROG_NAME_LENGTH - 4; i++) {
        read(fd, &int_name, 1);
        name[i] = int_name;
    }
    read(fd, description, COMMENT_LENGTH + 16);
    free(description);
    return name;
}

char *get_script(int fd, champion_t *champ)
{
    int size = 1;
    char *script = malloc(sizeof(char) * size);
    int n = 0;
    int i = 0;

    while (read(fd, &n, 1) > 0) {
        size += 2;
        script = realloc(script, size);
        if (n <= 16) {
            script[i] = '0';
            i++;
        }
        int_to_hex(n, script, i);
        i += (n <= 16) ? 1 : 2;
    }
    script[i++] = 0;
    champ->size_script = (size - 1) / 2;
    return script;
}

champion_t *get_champion(char *filepath)
{
    champion_t *champ = malloc(sizeof(champion_t));

    int fd = open(filepath, O_RDONLY);
    champ->name = get_name(fd);
    champ->script = get_script(fd, champ);
    champ->last_live = 0;
    champ->id = 0;
    close(fd);
    return champ;
}
