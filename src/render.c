/*
** EPITECH PROJECT, 2018
** bistro graphical bonus
** File description:
** bonus
*/

#include "prototypes.h"

void render(game_t *st)
{
    void (*render[NB_SCENES])(game_t *) = {play_scene0, play_scene1,
        play_scene2, play_scene3_4, play_scene3_4};

    sfRenderWindow_clear(st->window, sfBlack);
    render[st->scene](st);
    sfRenderWindow_display(st->window);
}