/*
** EPITECH PROJECT, 2018
** MUL_my_defender_2018
** File description:
** ally.c
*/

#include "prototypes.h"

int left_ally(ally_t *first, int random, game_t *game)
{
    int x = first->pos.x / 50;
    int y = first->pos.y / 50;

    if (game->scene1->map->tab[y][x - 1] != '-' && random == 0) {
        first->animation.top = 88;
        first->animation.left += 47;
        first->pos.x -= 10;
    }
    return (0);
}

int right_ally(ally_t *first, int random, game_t *game)
{
    int x = first->pos.x / 50;
    int y = first->pos.y / 50;

    if (game->scene1->map->tab[y][x + 2] != '-' && random == 1) {
        first->animation.top = 0;
        first->animation.left += 47;
        first->pos.x += 10;
    }
    return (0);
}

int up_ally(ally_t *first, int random, game_t *game)
{
    int x = first->pos.x / 50;
    int y = first->pos.y / 50;

    if (game->scene1->map->tab[y - 2][x] != '-' && random == 2) {
        first->animation.left += 47;
        first->pos.y -= 10;
    }
    return (0);
}

int down_ally(ally_t *first, int random, game_t *game)
{
    int x = first->pos.x / 50;
    int y = first->pos.y / 50;

    if (game->scene1->map->tab[y + 1][x] != '-' && random == 3) {
        first->animation.left += 47;
        first->pos.y += 10;
    }
    return (0);
}