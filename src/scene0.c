/*
** EPITECH PROJECT, 2018
** MUL_my_defender_2018
** File description:
** scene0.c
*/

#include "prototypes.h"

void set_menu(scene0_t *scene0)
{
    scene0->list_background = malloc(sizeof(background_t*) * 8);

    if (!scene0->list_background)
        return;
    for (int i = 0; i < 8; i++) {
        scene0->list_background[i] = malloc(sizeof(background_t));
        if (!scene0->list_background[i])
            return;
    }
    set_background(scene0->list_background[0], "menu/menu_background.png");
    set_background(scene0->list_background[1], "menu/menu_button_play.png");
    set_background(scene0->list_background[2], "menu/menu_button_help.png");
    set_background(scene0->list_background[3], "menu/menu_character.png");
    set_background(scene0->list_background[4], "menu/arrow_left.png");
    set_background(scene0->list_background[5], "menu/arrow_middle.png");
    set_background(scene0->list_background[6], "menu/arrow_right.png");
    set_background(scene0->list_background[7], "menu/menu_options.png");
    scene0->swap = 0;
    scene0->p = 1;
}

static void start_game(game_t *game)
{
    fs_open_file(game->scene1->map, "map/map1.txt");
    fs_open_file(game->scene1->wall, "map/wall1.txt");
    set_shop(game->scene1->shop);
    set_list_enemy(game->scene1->list_enemy[0], 220, 350);
    set_list_enemy(game->scene1->list_enemy[1], 490, 1030);
    set_list_enemy(game->scene1->list_enemy[2], 1100, 730);
    game->scene1->nbr_enemy = 18;
    game->scene1->list_ally = NULL;
}

static void display_scene0_play_return(game_t *game)
{
    if (sfKeyboard_isKeyPressed(sfKeyReturn)) {
        if (game->scene0->p == 0) {
            set_character(game->scene1->character, "character/thief.png");
            set_weapon(game->scene1->weapon, "weapon/knife.png");
        }
        if (game->scene0->p == 1) {
            set_character(game->scene1->character, "character/knight.png");
            set_weapon(game->scene1->weapon, "weapon/sword.png");
        }
        if (game->scene0->p == 2) {
            set_character(game->scene1->character, "character/wizard.png");
            set_weapon(game->scene1->weapon, "weapon/magic_wand.png");
        }
        start_game(game);
        game->scene = GAME;
    }
}

static void display_scene0_play(game_t *game)
{
    sfRenderWindow_drawSprite(game->window,
    game->scene0->list_background[SPRITE_CHAR_BG]->sp_background, NULL);
    if (key_pressed() == LEFT && game->scene0->p > 0)
        game->scene0->p--;
    if (key_pressed() == RIGHT && game->scene0->p < 2)
        game->scene0->p++;
    if (game->scene0->p == 0)
        sfRenderWindow_drawSprite(game->window,
        game->scene0->list_background[SPRITE_ARROW_LEFT]->sp_background, NULL);
    if (game->scene0->p == 1)
        sfRenderWindow_drawSprite(game->window,
        game->scene0->list_background[SPRITE_ARROW_RIGHT]->sp_background,
        NULL);
    if (game->scene0->p == 2)
        sfRenderWindow_drawSprite(game->window,
        game->scene0->list_background[SPRITE_ARROW_MIDDLE]->sp_background,
        NULL);
    if (sfKeyboard_isKeyPressed(sfKeyEscape))
        game->scene0->swap = 0;
    display_scene0_play_return(game);
}

void display_scene0(game_t *game)
{
    sfRenderWindow_drawSprite(game->window,
    game->scene0->list_background[SPRITE_MENU_BACKGROUND]->sp_background, NULL);
    if (game->scene0->swap == 2)
        display_scene0_play(game);
    if (game->scene0->swap == 3)
        game->scene = RULES;
    if (key_pressed() == UP && game->scene0->swap < 2)
        game->scene0->swap = 0;
    if (key_pressed() == DOWN && game->scene0->swap < 2)
        game->scene0->swap = 1;
    if (sfKeyboard_isKeyPressed(sfKeyReturn) && game->scene0->swap == 0)
        game->scene0->swap = 2;
    if (sfKeyboard_isKeyPressed(sfKeyReturn) && game->scene0->swap == 1)
        game->scene0->swap = 3;
    if (game->scene0->swap == 0)
        sfRenderWindow_drawSprite(game->window,
        game->scene0->list_background[SPRITE_PLAY_BUTTON]->sp_background, NULL);
    if (game->scene0->swap == 1)
        sfRenderWindow_drawSprite(game->window,
        game->scene0->list_background[SPRITE_HELP_BUTTON]->sp_background, NULL);
}