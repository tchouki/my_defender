/*
** EPITECH PROJECT, 2018
** MUL_my_defender_2018
** File description:
** scene1.c
*/

#include "prototypes.h"

void set_pause(scene4_t *scene4)
{
    scene4->list_background = malloc(sizeof(background_t*) * 3);
    if (!scene4->list_background)
        return;
    for (int i = 0; i < 3; i++)
        scene4->list_background[i] = malloc(sizeof(background_t));
    set_background(scene4->list_background[0], "menu/menu_pause.png");
    set_background(scene4->list_background[1], "menu/menu_pause_menu.png");
    set_background(scene4->list_background[2], "menu/menu_pause_play.png");
}

void display_scene4(game_t *game)
{
    sfVector2f mouse_pos = get_mouse_pos(game->window);

    sfRenderWindow_drawSprite(game->window,
    game->scene4->list_background[0]->sp_background, NULL);
    if (mouse_pos.x >= 742 && mouse_pos.x <= 1180 && mouse_pos.y >= 422 &&
        mouse_pos.y <= 544) {
        sfRenderWindow_drawSprite(game->window,
            game->scene4->list_background[2]->sp_background, NULL);
        if (sfMouse_isButtonPressed(sfMouseLeft))
            game->scene = GAME;
    }
    if (mouse_pos.x >= 380 && mouse_pos.x <= 1544 && mouse_pos.y >= 736 &&
        mouse_pos.y <= 864) {
        sfRenderWindow_drawSprite(game->window,
            game->scene4->list_background[1]->sp_background, NULL);
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            game->scene = MENU;
            game->scene0->swap = 0;
        }
    }
}