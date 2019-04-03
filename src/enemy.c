/*
** EPITECH PROJECT, 2018
** MUL_my_defender_2018
** File description:
** enemy.c
*/

#include "prototypes.h"

static void set_enemy2(enemy_t *enemy, char *name)
{
    int random = rand() % 40;
    sfVector2f scale = {2, 2};

    enemy->hp = 80;
    if (name[6] == 'b') {
        enemy->hp += random * 3;
        sfSprite_setScale(enemy->sp_enemy, scale);
    }
    else
        enemy->hp += random;
}

void set_enemy(enemy_t *enemy, char *name, int x, int y)
{
    sfVector2f origin = {0, 88};

    sfImage *i_enemy = sfImage_createFromFile(name);
    enemy->t_enemy = sfTexture_createFromImage(i_enemy, NULL);
    enemy->sp_enemy = sfSprite_create();
    if (!i_enemy || !enemy->t_enemy || !enemy->sp_enemy)
        return;
    enemy->pos.x = x;
    enemy->pos.y = y;
    enemy->animation.left = 0;
    enemy->animation.top = 0;
    enemy->animation.height = 88;
    enemy->animation.width = 47;
    enemy->start = 0;
    set_enemy2(enemy, name);
    sfSprite_setOrigin(enemy->sp_enemy, origin);
    sfSprite_setPosition(enemy->sp_enemy, enemy->pos);
    sfSprite_setTexture(enemy->sp_enemy, enemy->t_enemy,
    sfTrue);
    sfSprite_setTextureRect(enemy->sp_enemy, enemy->animation);
}

void enemy_attack(enemy_t *first, game_t *game)
{
    int x_c = game->scene1->character->pos.x;
    int y_c = game->scene1->character->pos.y;
    int x_e = first->pos.x;
    int y_e = first->pos.y;

    if (x_e - 50 <= x_c && x_e + 50 >= x_c && y_e - 50 <= y_c &&
        y_e + 50 >= y_c) {
        if (game->scene1->character->stat[0] > 2)
            game->scene1->character->stat[0] -=
        (15 - game->scene1->character->stat[2] / 10);
        else
            game->scene = LOOSE;
    }
}

void move_enemy(enemy_t *first, game_t *game)
{
    int x = first->pos.x / 50;
    int y = first->pos.y / 50;

    if (!game->scene1->market_status) {
        up_enemy(first, game, x, y);
        right_enemy(first, game, x, y);
        left_enemy(first, game, x, y);
        down_enemy(first, game, x, y);
        enemy_attack(first, game);
    }
    if (first->animation.left > 188)
        first->animation.left = 0;
    sfSprite_setTextureRect(first->sp_enemy,
    first->animation);
    sfSprite_setPosition(first->sp_enemy,
    first->pos);
    sfRenderWindow_drawSprite(game->window,
    first->sp_enemy, NULL);
}