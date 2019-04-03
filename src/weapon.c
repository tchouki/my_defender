/*
** EPITECH PROJECT, 2018
** MUL_my_defender_2018
** File description:
** weapon.c
*/

#include "prototypes.h"

void set_weapon(weapon_t *weapon, char *name)
{
    sfVector2f origin = {17.5, 88};
    sfImage *i_weapon = sfImage_createFromFile(name);
    weapon->t_weapon = sfTexture_createFromImage(i_weapon, NULL);
    weapon->sp_weapon = sfSprite_create();
    weapon->pos.x = 100;
    weapon->pos.y = 520;
    weapon->attack = 0;
    weapon->angle = 0;
    weapon->kill = 0;
    sfSprite_setPosition(weapon->sp_weapon, weapon->pos);
    sfSprite_setTexture(weapon->sp_weapon, weapon->t_weapon,
    sfTrue);
    sfSprite_setOrigin(weapon->sp_weapon, origin);
}

static game_t *weapon_on_enemy(game_t *game, int x)
{
    int x_c = game->scene1->character->pos.x;
    int y_c = game->scene1->character->pos.y;
    list_enemy_t *tmp = game->scene1->list_enemy[x];

    for (int i = 0; tmp->next != NULL && tmp->first != NULL;
        tmp = tmp->next, i++)
        if (x_c - 100 <= tmp->first->pos.x &&
            x_c + 100 >= tmp->first->pos.x &&
            y_c - 100 <= tmp->first->pos.y &&
            y_c + 100 >= tmp->first->pos.y && tmp->first != NULL) {
            game->scene1->list_enemy[x] =
            kill_enemy(game->scene1->list_enemy[x], i - 1, game);
            game->scene1->weapon->kill++;
            return (game);
        }
    return (game);
}

game_t *attack_weapon(game_t *game, int x)
{
    list_enemy_t *tmp = game->scene1->list_enemy[x];

    if (game->scene1->weapon->attack == 1 && tmp != NULL &&
        tmp->first != NULL && game->scene1->weapon->kill < 3)
        game = weapon_on_enemy(game, x);
    return (game);
}

void move_weapon2(game_t *game)
{
    sfVector2f pos = game->scene1->character->pos;

    pos.y -= 18;
    pos.x += 15;
    sfSprite_setPosition(game->scene1->weapon->sp_weapon, pos);
    sfRenderWindow_drawSprite(game->window,
    game->scene1->weapon->sp_weapon, NULL);
}

void move_weapon(game_t *game)
{
    if (game->scene1->weapon->attack == 1 &&
        game->scene1->weapon->angle <= 360) {
        game->scene1->weapon->angle += 90;
        sfSprite_setRotation(game->scene1->weapon->sp_weapon,
            game->scene1->weapon->angle);
    }
    if (sfKeyboard_isKeyPressed(sfKeySpace) &&
        game->scene1->weapon->attack == 0 && !game->scene1->market_status &&
        game->scene1->weapon->kill < 3) {
        game->scene1->weapon->attack = 1;
        sfMusic_play(game->scene1->character->sound);
    }
    if (game->scene1->weapon->angle == 360) {
        game->scene1->weapon->angle = 0;
        game->scene1->weapon->attack = 0;
        sfMusic_stop(game->scene1->character->sound);
    }
    move_weapon2(game);
}
