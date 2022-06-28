/*
** EPITECH PROJECT, 2021
** B-CPE-201-MPL-2-1-corewar-romain.very
** File description:
** process_win.c
*/

#include "bonus.h"

void process_event(window_t win)
{
    while (sfRenderWindow_pollEvent(win.window, &win.event)) {
        if (win.event.type == sfEvtClosed)
            sfRenderWindow_close(win.window);
        if (win.event.type == sfEvtKeyPressed
        && win.event.key.code == sfKeyEscape)
            sfRenderWindow_close(win.window);
    }
}

void process_window(window_t win)
{
    while (sfRenderWindow_isOpen(win.window)) {
        process_event(win);
        sfRenderWindow_clear(win.window, sfBlack);
        sfRenderWindow_drawText(win.window, win.text, NULL);
        sfRenderWindow_display(win.window);
    }
}
