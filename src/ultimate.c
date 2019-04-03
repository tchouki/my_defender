/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** draw_map.c
*/

#include "prototypes.h"

void knight_ultimate(game_t *game)
{
    game->scene1->character->stat[1] = 100;
    if (game->scene1->weapon->kill < 3) {
        game->scene1->weapon->attack = 1;
    }
    if (game->scene1->weapon->attack == 1 &&
    game->scene1->weapon->angle <= 360) {
        game->scene1->weapon->angle += 90;
        sfSprite_setRotation(game->scene1->weapon->sp_weapon,
        game->scene1->weapon->angle);
    }
    if (game->scene1->weapon->angle == 360) {
        game->scene1->weapon->angle = 0;
        game->scene1->weapon->attack = 0;
        sfMusic_stop(game->scene1->character->sound);
    }
    move_weapon2(game);
}

void thief_ultimate(game_t *st)
{
    st->scene1->hud->ult = 1;
    st->scene1->hud->speed = 20;
}

void reset(game_t *game)
{
    if (game->chk > 100 && (game->scene1->hud->ult == 1 ||
    game->scene1->hud->ult == 2 || game->scene1->hud->ult == 3)) {
        if (game->scene0->p == 1) {
            game->scene1->character->stat[1] -= 50;
        }
        game->scene1->hud->speed = 10;
        game->chk = 0;
        game->scene1->character->stat[4] = 0;
        game->scene1->hud->ult = 0;
    }
}

game_t *config_ultimate(game_t *game)
{
    game->chk++;
    if (sfKeyboard_isKeyPressed(sfKeyA) && game->scene == GAME) {
        if (game->scene1->character->stat[4] == 1 && game->scene0->p == 0) {
            game->chk = 0;
            thief_ultimate(game);
        }
        if (game->scene1->character->stat[4] == 1 && game->scene0->p == 1) {
            game->chk = 0;
            game->scene1->hud->ult = 2;
        }
        if (game->scene1->character->stat[4] == 1 && game->scene0->p == 2) {
            game->chk = 0;
            game->scene1->hud->ult = 3;
        }
    }
    game = render_ult_wizard(game);
    if (game->scene1->hud->ult == 2)
        knight_ultimate(game);
    reset(game);
    return (game);
}
