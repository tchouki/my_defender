/*
** EPITECH PROJECT, 2018
** file
** File description:
** filefile
*/

#include "prototypes.h"

void rect_life_bar(game_t *st)
{
    st->scene1->hud->life.top = 0;
    st->scene1->hud->life.left = 0;
    st->scene1->hud->life.width = 334;
    st->scene1->hud->life.height = 53;
}

static void move_life_bar(game_t *st)
{
    int width = 334;
    int life = st->scene1->character->stat[0];
    int new_width = (life * width) / st->scene1->character->stat[3];

    if (new_width <= 24)
        new_width = 24;
    st->scene1->hud->life.width = new_width;
    sfSprite_setTextureRect(st->scene1->hud->t_hud[SPRITE_LIFE]->
        sp_background, st->scene1->hud->life);
    sfRenderWindow_drawSprite(st->window,
        st->scene1->hud->t_hud[SPRITE_LIFE]->sp_background, NULL);
    if (st->scene1->hud->life.width <= 22) {
        st->scene = LOOSE;
    }
}

void render_life(game_t *st)
{
    sfVector2f pos = {1413.6, 914.4};
    sfVector2f scale = {0.72, 0.7};

    move_life_bar(st);
    sfSprite_setPosition(st->scene1->hud->t_hud[6]->sp_background, pos);
    sfSprite_setScale(st->scene1->hud->t_hud[6]->sp_background, scale);
    sfSprite_setTextureRect(st->scene1->hud->t_hud[SPRITE_LIFE]->
        sp_background, st->scene1->hud->life);
    sfRenderWindow_drawSprite(st->window,
        st->scene1->hud->t_hud[SPRITE_LIFE]->sp_background, NULL);
}