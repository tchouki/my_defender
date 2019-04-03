/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** draw_map.c
*/

#include "prototypes.h"

static void choose_sprite_wall_back3(game_t *game, int i, int j, sfVector2f pos)
{
    if (game->scene1->wall->tab[i][j] == 'p') {
        game->scene1->wall->animation.left = 100;
        sfSprite_setTexture(game->scene1->wall->sp_map,
            game->scene1->wall->t_map, sfTrue);
        sfSprite_setTextureRect(game->scene1->wall->sp_map,
            game->scene1->wall->animation);
        sfSprite_setPosition(game->scene1->wall->sp_map, pos);
        sfRenderWindow_drawSprite(game->window, game->scene1->wall->sp_map,
            NULL);
        game->scene1->wall->animation.top = 0;
    }
}

static void choose_sprite_wall_back2(game_t *game, int i, int j, sfVector2f pos)
{
    if (game->scene1->wall->tab[i][j] == 'o') {
        game->scene1->wall->animation.left = 0;
        sfSprite_setTexture(game->scene1->wall->sp_map,
            game->scene1->wall->t_map, sfTrue);
        sfSprite_setTextureRect(game->scene1->wall->sp_map,
            game->scene1->wall->animation);
        sfSprite_setPosition(game->scene1->wall->sp_map, pos);
        sfRenderWindow_drawSprite(game->window, game->scene1->wall->sp_map,
            NULL);
        game->scene1->wall->animation.top = 0;
    }
}

void choose_sprite_wall_back(game_t *game, int i, int j)
{
    sfVector2f pos = {j * 50, i * 50};

    game->scene1->wall->animation.left = 200;
    game->scene1->wall->animation.top = 50;
    if (game->scene1->wall->tab[i][j] == 'x')
        game->scene1->wall->animation.left = 50;
    if (game->scene1->wall->tab[i][j] == 'n')
        game->scene1->wall->animation.left = 100;
    if (game->scene1->wall->tab[i][j] == 'b')
        game->scene1->wall->animation.left = 0;
    choose_sprite_wall_back2(game, i, j, pos);
    choose_sprite_wall_back3(game, i, j, pos);
    sfSprite_setTexture(game->scene1->wall->sp_map,
        game->scene1->wall->t_map, sfTrue);
    sfSprite_setTextureRect(game->scene1->wall->sp_map,
        game->scene1->wall->animation);
    sfSprite_setPosition(game->scene1->wall->sp_map, pos);
    sfRenderWindow_drawSprite(game->window, game->scene1->wall->sp_map, NULL);
}