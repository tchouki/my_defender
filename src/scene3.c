/*
** EPITECH PROJECT, 2018
** MUL_my_defender_2018
** File description:
** scene1.c
*/

#include "prototypes.h"

static void set_option2(scene3_t *scene3)
{
    set_background(scene3->list_background[0], "menu/menu_options.png");
    set_background(scene3->list_background[1],
        "menu/menu_options_mouseclick.png");
    set_background(scene3->list_background[2], "menu/menu_options_z.png");
    set_background(scene3->list_background[3], "menu/menu_options_s.png");
    set_background(scene3->list_background[4], "menu/menu_options_q.png");
    set_background(scene3->list_background[5], "menu/menu_options_d.png");
    set_background(scene3->list_background[6], "menu/button_gameover.png");
    set_background(scene3->list_background[7],
        "menu/button_gameover_pressed.png");
}

void set_option(scene3_t *scene3)
{
    sfFont *font = sfFont_createFromFile("font/VCR_OSD_MONO_1.001.ttf");
    sfVector2f pos = {1300, 375};
    sfVector2f scale = {4, 4};
    char *string = "initialisation";

    scene3->list_background = malloc(sizeof(background_t*) * 8);
    if (!scene3->list_background)
        return;
    for (int i = 0; i < 8; i++) {
        scene3->list_background[i] = malloc(sizeof(background_t));
        if (!scene3->list_background[i])
            return;
    }
    scene3->text = sfText_create();
    set_option2(scene3);
    sfText_setFont(scene3->text, font);
    sfText_setString(scene3->text, string);
    sfText_setScale(scene3->text, scale);
    sfText_setPosition(scene3->text, pos);
}

static void display_scene33(game_t *game)
{
    sfVector2f mouse_pos = get_mouse_pos(game->window);

    if (mouse_pos.x >= calc_distance(game, 624, 'x') && mouse_pos.x <= calc_distance(game, 1298, 'x') &&
        mouse_pos.y >= calc_distance(game, 880, 'y') && mouse_pos.y <= calc_distance(game, 930, 'y')) {
        sfRenderWindow_drawSprite(game->window,
            game->scene3->list_background[6]->sp_background, NULL);
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            game->scene = MENU;
            game->scene0->swap = 0;
        }
    }
    else
        sfRenderWindow_drawSprite(game->window,
            game->scene3->list_background[7]->sp_background, NULL);
    sfMusic_setVolume(game->game_sound, game->volume);
    sfMusic_setVolume(game->scene1->sound, game->volume);
}

static void display_scene32(game_t *game)
{
    sfVector2f mouse_pos = get_mouse_pos(game->window);
    int last_volume = game->volume;

    if (key_pressed() == RIGHT)
        sfRenderWindow_drawSprite(game->window,
            game->scene3->list_background[5]->sp_background, NULL);
    if (mouse_pos.x >= calc_distance(game, 1184, 'x') && mouse_pos.x <= calc_distance(game, 1250, 'x') &&
        mouse_pos.y >= calc_distance(game, 408, 'y') && mouse_pos.y <= calc_distance(game, 482, 'y') &&
        sfMouse_isButtonPressed(sfMouseLeft) && game->volume >= 10)
        game->volume -= 10;
    if (mouse_pos.x >= calc_distance(game, 1532, 'x') && mouse_pos.x <= calc_distance(game, 1596, 'x') &&
        mouse_pos.y >= calc_distance(game, 408, 'y') && mouse_pos.y <= calc_distance(game, 482, 'y') &&
        sfMouse_isButtonPressed(sfMouseLeft) && game->volume <= 90)
        game->volume += 10;
    if (sfMouse_isButtonPressed(sfMouseLeft) && last_volume == game->volume)
        sfRenderWindow_drawSprite(game->window,
            game->scene3->list_background[1]->sp_background, NULL);
}

void display_scene3(game_t *game)
{
    char *string = my_put_nbr(game->volume);

    sfRenderWindow_drawSprite(game->window,
    game->scene3->list_background[0]->sp_background, NULL);
    sfText_setString(game->scene3->text, string);
    sfRenderWindow_drawText(game->window, game->scene3->text, NULL);
    if (key_pressed() == UP)
        sfRenderWindow_drawSprite(game->window,
            game->scene3->list_background[2]->sp_background, NULL);
    if (key_pressed() == DOWN)
        sfRenderWindow_drawSprite(game->window,
            game->scene3->list_background[3]->sp_background, NULL);
    if (key_pressed() == LEFT)
        sfRenderWindow_drawSprite(game->window,
            game->scene3->list_background[4]->sp_background, NULL);
    display_scene32(game);
    display_scene33(game);
}