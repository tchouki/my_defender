/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** draw_map.c
*/

#include "prototypes.h"

void rect_fire(game_t *st)
{
    st->scene1->hud->fire.top = 0;
    st->scene1->hud->fire.left = 0;
    st->scene1->hud->fire.width = 78;
    st->scene1->hud->fire.height = 156;
}

static game_t *enemy_on_fire(game_t *game, int x)
{
    list_enemy_t *tmp = game->scene1->list_enemy[x];
    sfVector2f pos = get_mouse_pos(game->window);
    int i = pos.x;
    int j = pos.y;

    for (int pos = 0; tmp->next != NULL; tmp = tmp->next, pos++)
        if (tmp->first->pos.x - 50 <= i &&
            tmp->first->pos.x + 25 >= i &&
            tmp->first->pos.y - 50 <= j &&
            tmp->first->pos.y + 25 >= j) {
            game->scene1->list_enemy[x] =
        kill_enemy(game->scene1->list_enemy[x], pos - 1, game);
        }
    return (game);
}

void move_fire(game_t *st)
{
    sfVector2f pos = get_mouse_pos(st->window);

    sfSprite_setPosition(st->scene1->hud->t_hud[SPRITE_FIRE]->sp_background,
        pos);
    if (st->scene1->hud->fire.left >= 700 - 78) {
        st->scene1->hud->fire.left = 0;
    } else
        st->scene1->hud->fire.left = st->scene1->hud->fire.left + 78;
}

game_t *render_ult_wizard(game_t *st)
{
    if (st->scene1->hud->ult == 3 && st->chk < 100) {
        sfSprite_setTextureRect(st->scene1->hud->t_hud[SPRITE_FIRE]->
            sp_background, st->scene1->hud->fire);
        sfRenderWindow_drawSprite(st->window,
            st->scene1->hud->t_hud[SPRITE_FIRE]->sp_background, NULL);
        move_fire(st);
        for (int i = 0; i < 3; i++)
            st = enemy_on_fire(st, i);
    }
    return (st);
}
