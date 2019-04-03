/*
** EPITECH PROJECT, 2018
** MUL_my_defender_2018
** File description:
** scene1.c
*/

#include "prototypes.h"

void set_gameover(scene2_t *scene2)
{
    sfFont *font = sfFont_createFromFile("font/VCR_OSD_MONO_1.001.ttf");
    sfVector2f pos = {1100, 420};
    sfVector2f scale = {7, 7};
    char *string = "initialisation";

    scene2->list_background = malloc(sizeof(background_t*) * 3);
    if (!scene2->list_background)
        return;
    for (int i = 0; i < 3; i++)
        scene2->list_background[i] = malloc(sizeof(background_t));
    scene2->text = sfText_create();
    set_background(scene2->list_background[0], "menu/menu_gameover.png");
    set_background(scene2->list_background[1], "menu/button_gameover.png");
    set_background(scene2->list_background[2],
        "menu/button_gameover_pressed.png");
    sfText_setFont(scene2->text, font);
    sfText_setString(scene2->text, string);
    sfText_setScale(scene2->text, scale);
    sfText_setPosition(scene2->text, pos);
}

void display_scene2(game_t *game)
{
    sfVector2f mouse_pos = get_mouse_pos(game->window);
    char *string = my_put_nbr(game->scene1->character->kill);

    sfRenderWindow_drawSprite(game->window,
    game->scene2->list_background[0]->sp_background, NULL);
    sfText_setString(game->scene2->text, string);
    sfRenderWindow_drawText(game->window, game->scene2->text, NULL);
    if (mouse_pos.x >= 624 && mouse_pos.x <= 1298 && mouse_pos.y >= 880 &&
        mouse_pos.y <= 930) {
        sfRenderWindow_drawSprite(game->window,
            game->scene2->list_background[1]->sp_background, NULL);
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            game->scene = MENU;
            game->scene0->swap = 0;
        }
    }
    else
        sfRenderWindow_drawSprite(game->window,
            game->scene2->list_background[2]->sp_background, NULL);
}