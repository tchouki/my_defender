/*
** EPITECH PROJECT, 2018
** MUL_my_defender_2018
** File description:
** character.c
*/

#include "prototypes.h"

void set_cheat(scene1_t *scene1)
{
    sfVector2f pos = {1680.0, 1059.0};

    sfSprite_setPosition(scene1->hud->t_hud[7]->sp_background, pos);
}

void draw_cheat(game_t *game)
{
    sfRenderWindow_drawSprite(game->window,
    game->scene1->hud->t_hud[7]->sp_background, NULL);
}