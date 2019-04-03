/*
** EPITECH PROJECT, 2018
** MUL_my_defender_2018
** File description:
** shop.c
*/

#include "prototypes.h"

void set_shop(shop_t *shop)
{
    sfVector2f pos = {0, 0};
    shop->background = malloc(sizeof(background_t));
    if (!shop->background)
        return;
    set_background(shop->background, "map/shop.png");
    shop->animation.left = 0;
    shop->animation.top = 150;
    shop->animation.height = 50;
    shop->animation.width = 50;
    shop->item = 0;
    shop->coins = 0;
    sfSprite_setPosition(shop->background->sp_background, pos);
    sfSprite_setTextureRect(shop->background->sp_background, shop->animation);
}

static void after_buy4_6(shop_t *shop)
{
    if (shop->item == 4) {
        shop->animation.left = 100;
        shop->animation.top = 150;
    }
    if (shop->item == 5) {
        shop->animation.left = 0;
        shop->animation.top = 250;
    }
    if (shop->item == 6) {
        shop->animation.left = 100;
        shop->animation.top = 250;
    }
}

static void after_buy1_3(shop_t *shop)
{
    if (shop->item == 0) {
        shop->animation.left = 0;
        shop->animation.top = 0;
    }
    if (shop->item == 1) {
        shop->animation.left = 0;
        shop->animation.top = 50;
    }
    if (shop->item == 2) {
        shop->animation.left = 100;
        shop->animation.top = 50;
    }
    if (shop->item == 3) {
        shop->animation.left = 0;
        shop->animation.top = 150;
    }
}

void display_shop(game_t *game)
{
    sfVector2f mouse_pos = get_mouse_pos(game->window);

    see_money_item(game, mouse_pos, game->scene1->market_status);
    choose_item(game, mouse_pos, game->scene1->market_status);
    after_buy1_3(game->scene1->shop);
    after_buy4_6(game->scene1->shop);
    sfSprite_setPosition(game->scene1->shop->background->sp_background, mouse_pos);
    sfRenderWindow_drawSprite(game->window,
    game->scene1->shop->background->sp_background, NULL);
}