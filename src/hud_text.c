/*
** EPITECH PROJECT, 2018
** MUL_my_defender_2018
** File description:
** scene0.c
*/

#include "prototypes.h"

void set_hud_text(scene1_t *scene1)
{
    sfVector2f pos_attack = {1414, 973};
    sfVector2f pos_def = {1414, 1005};
    sfVector2f pos_coin = {1570, 1004};
    sfVector2f scale = {0.5, 0.5};
    char *string = "initialisation";
    sfFont *font = sfFont_createFromFile("font/VCR_OSD_MONO_1.001.ttf");

    scene1->hud->text = malloc(sizeof(sfText*) * 3);
    if (!scene1->hud->text)
        return;
    for (int i = 0; i < 3; i++) {
        scene1->hud->text[i] = sfText_create();
        sfText_setFont(scene1->hud->text[i], font);
        sfText_setString(scene1->hud->text[i], string);
        sfText_setScale(scene1->hud->text[i], scale);
    }
    sfText_setPosition(scene1->hud->text[0], pos_attack);
    sfText_setPosition(scene1->hud->text[1], pos_def);
    sfText_setPosition(scene1->hud->text[2], pos_coin);
}

void modify_text(game_t *game)
{
    char *string_coins = my_put_nbr(game->scene1->shop->coins);
    char *string_attack = my_put_nbr(game->scene1->character->stat[1]);
    char *string_defense = my_put_nbr(game->scene1->character->stat[2]);

    if (!string_coins)
        string_coins = "0";
    if (!string_attack)
        string_attack = "0";
    if (!string_defense)
        string_defense = "0";
    sfText_setString(game->scene1->hud->text[0], string_attack);
    sfText_setString(game->scene1->hud->text[1], string_defense);
    sfText_setString(game->scene1->hud->text[2], string_coins);
    for (int i = 0; i < 3; i++)
        sfRenderWindow_drawText(game->window,
            game->scene1->hud->text[i], NULL);
}