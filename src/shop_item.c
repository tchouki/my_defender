/*
** EPITECH PROJECT, 2018
** MUL_my_defender_2018
** File description:
** shop.c
*/

#include "prototypes.h"

static void choose_item2(game_t *game, sfVector2f pos, int market_status)
{
    if (sfMouse_isButtonPressed(sfMouseLeft) && pos.x > calc_distance(game, 1835, 'x') && pos.x < calc_distance(game, 1885, 'x')
        && pos.y > calc_distance(game, 870, 'y') && pos.y < calc_distance(game, 920, 'y') && market_status && game->scene1->shop->coins >= 40) {
        game->scene1->shop->item = 4;
        game->scene1->shop->coins -= 40;
    }
    if (sfMouse_isButtonPressed(sfMouseLeft) && pos.x > calc_distance(game, 1785, 'x') && pos.x < calc_distance(game, 1835, 'x')
        && pos.y > calc_distance(game, 930, 'y') && pos.y < calc_distance(game, 980, 'y') && market_status && game->scene1->shop->coins >= 60) {
        game->scene1->shop->item = 5;
        game->scene1->shop->coins -= 60;
    }
    if (sfMouse_isButtonPressed(sfMouseLeft) && pos.x > calc_distance(game, 1835, 'x') && pos.x < calc_distance(game, 1885, 'x')
        && pos.y > calc_distance(game, 930, 'y') && pos.y < calc_distance(game, 980, 'y') && market_status && game->scene1->shop->coins >= 60) {
        game->scene1->shop->item = 6;
        game->scene1->shop->coins -= 60;
    }
}

void choose_item(game_t *game, sfVector2f pos, int market_status)
{
    if (sfMouse_isButtonPressed(sfMouseLeft) && pos.x > calc_distance(game, 1785, 'x') && pos.x < calc_distance(game, 1835, 'x')
        && pos.y > calc_distance(game, 820, 'y') && pos.y < calc_distance(game, 870, 'y') && market_status && game->scene1->shop->coins >= 20) {
        game->scene1->shop->item = 1;
        game->scene1->shop->coins -= 20;
    }
    if (sfMouse_isButtonPressed(sfMouseLeft) && pos.x > calc_distance(game, 1835, 'x') && pos.x < calc_distance(game, 1885, 'x')
        && pos.y > calc_distance(game, 820, 'y') && pos.y < calc_distance(game, 870, 'y') && market_status && game->scene1->shop->coins >= 20) {
        game->scene1->shop->item = 2;
        game->scene1->shop->coins -= 20;
    }
    if (sfMouse_isButtonPressed(sfMouseLeft) && pos.x > calc_distance(game, 1785, 'x') && pos.x < calc_distance(game, 1835, 'x')
        && pos.y > calc_distance(game, 870, 'y') && pos.y < calc_distance(game, 920, 'y') && market_status && game->scene1->shop->coins >= 40) {
        game->scene1->shop->item = 3;
        game->scene1->shop->coins -= 40;
    }
    choose_item2(game, pos, market_status);
    sfSprite_setTextureRect(game->scene1->shop->background->sp_background, game->scene1->shop->animation);
}

static void see_money_item2(game_t *game, sfVector2f pos, int market_status)
{
    if (pos.x > calc_distance(game, 1835, 'x') && pos.x < calc_distance(game, 1885, 'x') && pos.y > calc_distance(game, 870, 'y') && pos.y < calc_distance(game, 920, 'y') &&
        market_status) {
        game->scene1->shop->animation.left = 50;
        game->scene1->shop->animation.top = 100;
    }
    if (pos.x > calc_distance(game, 1785, 'x') && pos.x < calc_distance(game, 1835, 'x') && pos.y > calc_distance(game, 930, 'y') && pos.y < calc_distance(game, 980, 'y') &&
        market_status) {
        game->scene1->shop->animation.left = 100;
        game->scene1->shop->animation.top = 100;
    }
    if (pos.x > calc_distance(game, 1835, 'x') && pos.x < calc_distance(game, 1885, 'x') && pos.y > calc_distance(game, 930, 'y') && pos.y < calc_distance(game, 980, 'y') &&
        market_status) {
        game->scene1->shop->animation.left = 100;
        game->scene1->shop->animation.top = 100;
    }
}

void see_money_item(game_t *game, sfVector2f pos, int market_status)
{
    if (pos.x > calc_distance(game, 1785, 'x') && pos.x < calc_distance(game, 1835, 'x') && pos.y > calc_distance(game, 820, 'y') && pos.y < calc_distance(game, 870, 'y') &&
        market_status) {
        game->scene1->shop->animation.left = 0;
        game->scene1->shop->animation.top = 100;
    }
    if (pos.x > calc_distance(game, 1835, 'x') && pos.x < calc_distance(game, 1885, 'x') && pos.y > calc_distance(game, 820, 'y') && pos.y < calc_distance(game, 870, 'y') &&
        market_status) {
        game->scene1->shop->animation.left = 0;
        game->scene1->shop->animation.top = 100;
    }
    if (pos.x > calc_distance(game, 1785, 'x') && pos.x < calc_distance(game, 1835, 'x') && pos.y > calc_distance(game, 870, 'y') && pos.y < calc_distance(game, 920, 'y') &&
        market_status) {
        game->scene1->shop->animation.left = 50;
        game->scene1->shop->animation.top = 100;
    }
    see_money_item2(game, pos, market_status);
    sfSprite_setTextureRect(game->scene1->shop->background->sp_background, game->scene1->shop->animation);
}