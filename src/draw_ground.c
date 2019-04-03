/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** draw_map.c
*/

#include "prototypes.h"

void choose_sprite_ground(game_t *game, int i, int j)
{
    sfVector2f pos = {j * 50, i * 50};

    game->scene1->map->animation.left = 0;
    if (game->scene1->map->tab[i][j] == 'o')
        game->scene1->map->animation.top = 200;
    if (game->scene1->map->tab[i][j] == '-')
        game->scene1->map->animation.top = 250;
    sfSprite_setTexture(game->scene1->map->sp_map, game->scene1->map->t_map,
        sfTrue);
    sfSprite_setTextureRect(game->scene1->map->sp_map,
        game->scene1->map->animation);
    sfSprite_setPosition(game->scene1->map->sp_map, pos);
    sfRenderWindow_drawSprite(game->window, game->scene1->map->sp_map, NULL);
}