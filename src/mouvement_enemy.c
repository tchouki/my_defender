/*
** EPITECH PROJECT, 2018
** MUL_my_defender_2018
** File description:
** enemy.c
*/

#include "prototypes.h"

int left_enemy(enemy_t *first, game_t *game, int x, int y)
{
    int can_move_left = 0;

    if (game->scene1->map->tab[y][x - 1] != '-')
        can_move_left = 1;
    if (game->scene1->character->pos.x / 50 <= x && can_move_left) {
        first->animation.top = 88;
        first->animation.left += 47;
        first->pos.x -= 5;
    }
    return (0);
}

int right_enemy(enemy_t *first, game_t *game, int x, int y)
{
    int can_move_right = 0;

    if (game->scene1->map->tab[y][x + 2] != '-')
        can_move_right = 1;
    if (game->scene1->character->pos.x / 50 > x && can_move_right) {
        first->animation.top = 0;
        first->animation.left += 47;
        first->pos.x += 5;
    }
    return (0);
}

int up_enemy(enemy_t *first, game_t *game, int x, int y)
{
    int can_move_up = 0;

    if (game->scene1->map->tab[y - 2][x] != '-')
        can_move_up = 1;
    if (game->scene1->character->pos.y / 50 <= y && can_move_up) {
        first->animation.left += 47;
        first->pos.y -= 5;
    }
    return (0);
}

int down_enemy(enemy_t *first, game_t *game, int x, int y)
{
    int can_move_down = 0;

    if (game->scene1->map->tab[y + 1][x] != '-')
        can_move_down = 1;
    if (game->scene1->character->pos.y / 50 > y && can_move_down) {
        first->animation.left += 47;
        first->pos.y += 5;
    }
    return (0);
}