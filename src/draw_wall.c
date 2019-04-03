/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** draw_map.c
*/

#include "prototypes.h"

static void choose_sprite_door2(game_t *game, int i, int j)
{
    if (game->scene1->wall->tab[i][j] == 'e') {
        game->scene1->wall->animation.left = 100;
        game->scene1->wall->animation.top = 100;
    }
    if (game->scene1->wall->tab[i][j] == 'd') {
        game->scene1->wall->animation.left = 100;
        game->scene1->wall->animation.top = 150;
    }
    if (game->scene1->wall->tab[i][j] == 'r') {
        game->scene1->wall->animation.left = 150;
        game->scene1->wall->animation.top = 100;
    }
    if (game->scene1->wall->tab[i][j] == 'f') {
        game->scene1->wall->animation.left = 150;
        game->scene1->wall->animation.top = 150;
    }
}

static void choose_sprite_door(game_t *game, int i, int j)
{
    if (game->scene1->wall->tab[i][j] == 'a') {
        game->scene1->wall->animation.left = 0;
        game->scene1->wall->animation.top = 100;
    }
    if (game->scene1->wall->tab[i][j] == 'q') {
        game->scene1->wall->animation.left = 0;
        game->scene1->wall->animation.top = 150;
    }
    if (game->scene1->wall->tab[i][j] == 'z') {
        game->scene1->wall->animation.left = 50;
        game->scene1->wall->animation.top = 100;
    }
    if (game->scene1->wall->tab[i][j] == 's') {
        game->scene1->wall->animation.left = 50;
        game->scene1->wall->animation.top = 150;
    }
    choose_sprite_door2(game, i, j);
}

static void choose_sprite_wall3(game_t *game, int i, int j, sfVector2f pos)
{
    if (game->scene1->wall->tab[i][j] == 'h') {
        game->scene1->wall->animation.top = 50;
        game->scene1->wall->animation.left = 100;
    }
    if (game->scene1->wall->tab[i][j] == 'g') {
        game->scene1->wall->animation.top = 50;
        game->scene1->wall->animation.left = 0;
    }
    if (game->scene1->wall->tab[i][j] == 'm') {
        game->scene1->wall->animation.top = 50;
        game->scene1->wall->animation.left = 100;
        sfSprite_setTexture(game->scene1->wall->sp_map,
            game->scene1->wall->t_map, sfTrue);
        sfSprite_setTextureRect(game->scene1->wall->sp_map,
            game->scene1->wall->animation);
        sfSprite_setPosition(game->scene1->wall->sp_map, pos);
        sfRenderWindow_drawSprite(game->window,
            game->scene1->wall->sp_map, NULL);
        game->scene1->wall->animation.top = 0;
    }
}

static void choose_sprite_wall2(game_t *game, int i, int j, sfVector2f pos)
{
    if (game->scene1->wall->tab[i][j] == 'y') {
        game->scene1->wall->animation.left = 100;
    }
    if (game->scene1->wall->tab[i][j] == 'k') {
        game->scene1->wall->animation.left = 50;
        game->scene1->wall->animation.top = 50;
    }
    if (game->scene1->wall->tab[i][j] == 'l') {
        game->scene1->wall->animation.top = 50;
        game->scene1->wall->animation.left = 0;
        sfSprite_setTexture(game->scene1->wall->sp_map,
            game->scene1->wall->t_map, sfTrue);
        sfSprite_setTextureRect(game->scene1->wall->sp_map,
            game->scene1->wall->animation);
        sfSprite_setPosition(game->scene1->wall->sp_map, pos);
        sfRenderWindow_drawSprite(game->window,
            game->scene1->wall->sp_map, NULL);
        game->scene1->wall->animation.top = 0;
    }
}

void choose_sprite_wall(game_t *game, int i, int j)
{
    sfVector2f pos = {j * 50, i * 50};

    game->scene1->wall->animation.top = 0;
    if (game->scene1->wall->tab[i][j] == 't') {
        game->scene1->wall->animation.left = 0;
    }
    if (game->scene1->wall->tab[i][j] == '-') {
        game->scene1->wall->animation.left = 50;
    }
    choose_sprite_wall2(game, i, j, pos);
    choose_sprite_wall3(game, i, j, pos);
    choose_sprite_door(game, i, j);
    sfSprite_setTexture(game->scene1->wall->sp_map, game->scene1->wall->t_map,
        sfTrue);
    sfSprite_setTextureRect(game->scene1->wall->sp_map,
        game->scene1->wall->animation);
    sfSprite_setPosition(game->scene1->wall->sp_map, pos);
    sfRenderWindow_drawSprite(game->window, game->scene1->wall->sp_map,
        NULL);
}