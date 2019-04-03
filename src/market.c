/*
** EPITECH PROJECT, 2018
** MUL_my_defender_2018
** File description:
** market.c
*/

#include "prototypes.h"

static int get_market(game_t *st)
{
    if (get_mouse_pos(st->window).x >= calc_distance(st, 1627, 'x') &&
    get_mouse_pos(st->window).x <= calc_distance(st, 1675, 'x') && get_mouse_pos(st->window).y >=
    calc_distance(st, 977, 'y') && get_mouse_pos(st->window).y <= calc_distance(st, 1023, 'y')) {
        return (1);
    }
    return (0);
}

static int hide_market(game_t *st)
{
    if (get_mouse_pos(st->window).x >= calc_distance(st, 1828, 'x') &&
    get_mouse_pos(st->window).x <= calc_distance(st, 1845, 'x') && get_mouse_pos(st->window).y >=
    calc_distance(st, 1023, 'y') && get_mouse_pos(st->window).y <= calc_distance(st, 1041, 'y') &&
    st->scene1->market_status == 1)
        return (1);
    return (0);
}

static void move_market(game_t *st)
{
    sfVector2f move = {0, 0};
    sfVector2f pos =
    sfSprite_getPosition(st->scene1->hud->t_hud[SPRITE_MARKET]->sp_background);
    sfVector2f pos2 =
    sfSprite_getPosition(st->scene1->hud->t_hud[SPRITE_ARRSHOP]->sp_background);

    if (st->scene1->market_status == 1 && pos.y > 762.4 && pos2.y > 762.4) {
        move.y -= 50;
        sfSprite_move(st->scene1->hud->t_hud[SPRITE_MARKET]->sp_background,
            move);
        sfSprite_move(st->scene1->hud->t_hud[SPRITE_ARRSHOP]->sp_background,
            move);
    } else if (st->scene1->market_status == 0 &&
        pos.y < 1260.4 && pos2.y < 1260.4) {
        move.y += 50;
        sfSprite_move(st->scene1->hud->t_hud[SPRITE_MARKET]->sp_background,
            move);
        sfSprite_move(st->scene1->hud->t_hud[SPRITE_ARRSHOP]->sp_background,
            move);
    }
}

void market(game_t *st)
{
    move_market(st);
    if (get_market(st)) {
        sfRenderWindow_drawSprite(st->window,
            st->scene1->hud->t_hud[SPRITE_BUTTON_M]->sp_background, NULL);
        if (st->event.type == sfEvtMouseButtonPressed)
            st->scene1->market_status = 1;
    }
    if (hide_market(st)) {
        sfRenderWindow_drawSprite(st->window,
        st->scene1->hud->t_hud[SPRITE_ARRSHOP]->sp_background, NULL);
        if (st->event.type == sfEvtMouseButtonPressed)
            st->scene1->market_status = 0;
    }
}