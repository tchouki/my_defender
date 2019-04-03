/*
** EPITECH PROJECT, 2018
** MUL_my_defender_2018
** File description:
** character.c
*/

#include "prototypes.h"

void left_character(game_t *game, int x, int y)
{
    int can_move_left = 0;

    if (game->scene1->map->tab[y][x] != '-' &&
        game->scene1->map->tab[y][x] != '2')
        can_move_left = 1;
    if (key_pressed() == LEFT && can_move_left) {
        game->scene1->character->animation.top = 88;
        game->scene1->character->animation.left += 47;
        game->scene1->character->pos.x -= game->scene1->hud->speed;
    }

}

void right_character(game_t *game, int x, int y)
{
    int can_move_right = 0;

    if (game->scene1->map->tab[y][x + 1] != '-' &&
        game->scene1->map->tab[y][x + 1] != '2')
        can_move_right = 1;
    if (key_pressed() == RIGHT && can_move_right) {
        game->scene1->character->animation.top = 0;
        game->scene1->character->animation.left += 47;
        game->scene1->character->pos.x += game->scene1->hud->speed;
    }
}

void up_character(game_t *game, int x, int y)
{
    int can_move_up = 0;

    if (game->scene1->map->tab[y - 1][x] != '-' &&
        game->scene1->map->tab[y - 1][x] != '2')
        can_move_up = 1;
    if (key_pressed() == UP && can_move_up) {
        game->scene1->character->animation.left += 47;
        game->scene1->character->pos.y -= game->scene1->hud->speed;
    }
}

void down_character(game_t *game, int x, int y)
{
    int can_move_down = 0;

    if (game->scene1->map->tab[y][x] != '-' &&
        game->scene1->map->tab[y][x] != '2')
        can_move_down = 1;
    if (key_pressed() == DOWN && can_move_down) {
        game->scene1->character->animation.left += 47;
        game->scene1->character->pos.y += game->scene1->hud->speed;
    }
}
