/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** draw_map.c
*/

#include "prototypes.h"

static void place_trap_map(game_t *game, sfVector2f mouse_pos)
{
    int x = (int)mouse_pos.x;
    int y = (int)mouse_pos.y;

    if (game->scene1->map->tab[y / 50][x / 50] == 'o' &&
        sfMouse_isButtonPressed(sfMouseLeft)) {
        if (game->scene1->shop->item == 1)
            game->scene1->map->tab[y / 50][x / 50] = '1';
        if (game->scene1->shop->item == 2)
            game->scene1->map->tab[y / 50][x / 50] = '2';
        if (game->scene1->shop->item == 3)
            game->scene1->map->tab[y / 50][x / 50] = '3';
        if (game->scene1->shop->item == 4)
            game->scene1->map->tab[y / 50][x / 50] = '4';
        if (game->scene1->shop->item == 5)
            game->scene1->map->tab[y / 50][x / 50] = '5';
        if (game->scene1->shop->item == 6)
            game->scene1->map->tab[y / 50][x / 50] = '6';
        game->scene1->shop->item = 0;
    }
}

void place_trap(game_t *game)
{
    sfVector2f mouse_pos = get_mouse_pos(game->window);

    if (mouse_pos.x > WIN_WIDTH)
        mouse_pos.x = 0;
    if (mouse_pos.y > 1050)
        mouse_pos.y = 0;
    place_trap_map(game, mouse_pos);
}

static void change_sprite_mouse4_6(game_t *game, int i, int j)
{
    if (game->scene1->map->tab[i][j] == '4') {
        game->scene1->map->animation.left = 200;
    }
    if (game->scene1->map->tab[i][j] == '5') {
        game->scene1->map->animation.top = 250;
        game->scene1->map->animation.left = 50;
    }
    if (game->scene1->map->tab[i][j] == '6') {
        game->scene1->map->animation.top = 250;
        game->scene1->map->animation.left = 100;
    }
}

static void change_sprite_mouse1_3(game_t *game, int i, int j)
{
    if (game->scene1->map->tab[i][j] == '1') {
        game->scene1->map->animation.left = 50;
    }
    if (game->scene1->map->tab[i][j] == '2') {
        game->scene1->map->animation.left = 100;
    }
    if (game->scene1->map->tab[i][j] == '3') {
        game->scene1->map->animation.left = 150;
    }
}

void choose_sprite_trap(game_t *game, int i, int j)
{
    sfVector2f pos = {j * 50, i * 50};

    game->scene1->map->animation.left = 0;
    game->scene1->map->animation.top = 200;
    change_sprite_mouse1_3(game, i, j);
    change_sprite_mouse4_6(game, i, j);
    if (game->scene1->map->tab[i][j] == '-') {
        game->scene1->map->animation.left = 0;
        game->scene1->map->animation.top = 250;
    }
    sfSprite_setTexture(game->scene1->map->sp_map,
        game->scene1->map->t_map, sfTrue);
    sfSprite_setTextureRect(game->scene1->map->sp_map,
        game->scene1->map->animation);
    sfSprite_setPosition(game->scene1->map->sp_map, pos);
    sfRenderWindow_drawSprite(game->window,
        game->scene1->map->sp_map, NULL);
}