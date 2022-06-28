/*
** EPITECH PROJECT, 2021
** B-CPE-201-MPL-2-1-corewar-romain.very
** File description:
** main.c
*/

#include "bonus.h"

char *get_text(champion_t **champions, int nb_champs)
{
    char *text = malloc(sizeof(char) * (MEM_SIZE * 2));
    int between = MEM_SIZE * 2;
    int i = 0;
    int j = 0;
    int ind = 0;

    for (; i < nb_champs; i++)
        between -= champions[i]->size_script * 2;
    for (i = 0; i < nb_champs; i++) {
        for (j = 0; champions[i]->script[j] != '\0'; j++, ind++)
            text[ind] = champions[i]->script[j];
        for (j = 0; j < between / nb_champs; j++, ind++)
            text[ind] = '0';
    }
    return text;
}

window_t init_window(champion_t **champions, int nb_champs)
{
    window_t win;

    win.window = sfRenderWindow_create((sfVideoMode){1920, 1080, 32}, "Corewar",
    sfResize | sfClose, NULL);
    win.champions = champions;
    win.text = sfText_create();
    sfText_setString(win.text, get_text(champions, nb_champs));
    sfText_setFont(win.text, sfFont_createFromFile("assets/font.otf"));
    sfText_setCharacterSize(win.text, 20);
    return (win);
}

int main(int ac, char **av)
{
    champion_t **champions = malloc(sizeof(champion_t *) * (ac - 1));
    window_t win;
    int i = 1;

    for (; i < ac; i++)
        champions[i - 1] = get_champion(av[i]);
    win = init_window(champions, ac - 1);
    process_window(win);
    return 0;
}
