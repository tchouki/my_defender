/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** draw_map.c
*/

#include "prototypes.h"

void solo(game_t *game)
{
    for (int i = 0; game->scene1->map->tab[i] != NULL; i++)
        for (int j = 0; game->scene1->map->tab[i][j] != '|'; j++) {
            choose_sprite_ground(game, i, j);
            choose_sprite_trap(game, i, j);
            choose_sprite_wall_back(game, i, j);
        }
}

void draw_wall(game_t *game)
{
    for (int i = 0; game->scene1->wall->tab[i] != NULL; i++)
        for (int j = 0; game->scene1->wall->tab[i][j] != '|'; j++)
            choose_sprite_wall(game, i, j);
}