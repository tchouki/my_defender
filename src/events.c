/*
** EPITECH PROJECT, 2018
** bistro graphical bonus
** File description:
** bonus
*/

#include "prototypes.h"

void analyse_events(game_t *st)
{
    if (st->event.type == sfEvtClosed ||
    (sfKeyboard_isKeyPressed(sfKeyEscape) && st->scene == MENU &&
        st->scene0->swap == 0))
        sfRenderWindow_close(st->window);
    if (sfKeyboard_isKeyPressed(sfKeyEscape) && st->scene == GAME) {
        st->scene = PAUSE;
    }
    if (sfKeyboard_isKeyPressed(sfKeyEscape) && st->scene == RULES) {
        st->scene = MENU;
        st->scene0->swap = 0;
    }
    if (sfKeyboard_isKeyPressed(sfKeyEscape) && st->scene == LOOSE) {
        st->scene = MENU;
        st->scene0->swap = 0;
    }
    if (sfKeyboard_isKeyPressed(sfKeyEscape) && st->scene == PAUSE) {
        st->scene = MENU;
        st->scene0->swap = 0;
    }
}