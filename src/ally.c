/*
** EPITECH PROJECT, 2018
** MUL_my_defender_2018
** File description:
** ally.c
*/

#include "prototypes.h"

static void set_ally_stat(ally_t *ally)
{
    ally->start = 1;
    ally->hp = 10;
}

void set_ally(ally_t *ally, char *name, int x, int y)
{
    sfVector2f origin = {0, 88};

    sfImage *i_ally = sfImage_createFromFile(name);
    ally->t_ally = sfTexture_createFromImage(i_ally, NULL);
    ally->sp_ally = sfSprite_create();
    if (!ally->sp_ally || !i_ally || !ally->t_ally)
        return;
    ally->pos.x = x;
    ally->pos.y = y;
    ally->animation.left = 0;
    ally->animation.top = 0;
    ally->animation.height = 88;
    ally->animation.width = 47;
    set_ally_stat(ally);
    sfSprite_setOrigin(ally->sp_ally, origin);
    sfSprite_setPosition(ally->sp_ally, ally->pos);
    sfSprite_setTexture(ally->sp_ally, ally->t_ally,
    sfTrue);
    sfSprite_setTextureRect(ally->sp_ally, ally->animation);
}

void move_ally(ally_t *first, game_t *game)
{
    int random = rand() % 4;

    if (!game->scene1->market_status) {
        up_ally(first, random, game);
        right_ally(first, random, game);
        left_ally(first, random, game);
        down_ally(first, random, game);
    }
    if (first->animation.left > 188)
        first->animation.left = 0;
    sfSprite_setTextureRect(first->sp_ally,
    first->animation);
    sfSprite_setPosition(first->sp_ally,
    first->pos);
    sfRenderWindow_drawSprite(game->window,
    first->sp_ally, NULL);
}