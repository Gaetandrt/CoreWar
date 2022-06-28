/*
** EPITECH PROJECT, 2022
** B-CPE-201-MPL-2-1-corewar-romain.very
** File description:
** bonus
*/

#ifndef BONUS_H_
    #define BONUS_H_

    #include "my.h"
    #include "op.h"
    #include <SFML/Graphics.h>
    #include <SFML/System.h>
    #include <SFML/Audio.h>

typedef struct champion_s {
    char *name;
    char *script;
    long int id;
    int last_live;
    int size_script;
} champion_t;

typedef struct window_s {
    sfRenderWindow *window;
    champion_t **champions;
    sfEvent event;
    sfText *text;
} window_t;

champion_t *get_champion(char *filepath);

#endif /* !BONUS_H_ */
