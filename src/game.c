/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** main.c
*/

#include "prototypes.h"

void play_scene0(game_t *game)
{
    if (game->scene == MENU) {
        display_scene0(game);
    }
}

static void play_scene12(game_t *game)
{
    for (int i = 0; i < 3; i++) {
        game = move_list_enemy(game, i);
        game = attack_weapon(game, i);
        check_all_trap(game, i);
    }
    if (game->scene1->list_ally != NULL)
        game = move_list_ally(game);
    draw_wall(game);
    game = config_ultimate(game);
    display_hud(game);
    display_shop(game);
    sfMusic_setVolume(game->scene1->sound, game->volume);
    sfMusic_setVolume(game->scene1->character->sound, game->volume);
}

void play_scene1(game_t *game)
{
    static int unlock_weapon = 0;

    if (game->scene == GAME) {
        if (unlock_weapon == 10) {
            game->scene1->weapon->kill = 0;
            unlock_weapon = 0;
        }
        unlock_weapon++;
        solo(game);
        place_trap(game);
        move_weapon(game);
        move_character(game);
        play_scene12(game);
    }
}

void play_scene2(game_t *game)
{
    if (game->scene == LOOSE) {
        display_scene2(game);
    }
}

void play_scene3_4(game_t *game)
{
    if (game->scene == RULES) {
        display_scene3(game);
    }
    if (game->scene == PAUSE) {
        display_scene4(game);
    }
}
