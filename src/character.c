/*
** EPITECH PROJECT, 2018
** MUL_my_defender_2018
** File description:
** character.c
*/

#include "prototypes.h"

static void set_character_stat(character_t *character, char *name)
{
    if (name[10] == 'k') {
        character->stat[0] = 1200;
        character->stat[1] = 50;
        character->stat[2] = 100;
        character->stat[3] = 1200;
    }
    if (name[10] == 'w') {
        character->stat[0] = 800;
        character->stat[1] = 100;
        character->stat[2] = 50;
        character->stat[3] = 800;
    }
    if (name[10] == 't') {
        character->stat[0] = 1000;
        character->stat[1] = 75;
        character->stat[2] = 75;
        character->stat[3] = 1000;
    }
    character->stat[4] = 0;
    character->kill = 0;
}

static void set_character2(character_t *character)
{
    character->pos.x = 1500;
    character->pos.y = 200;
    character->animation.left = 0;
    character->animation.top = 0;
    character->animation.height = 88;
    character->animation.width = 47;
}

void set_character(character_t *character, char *name)
{
    sfVector2f origin = {0, 88};

    sfImage *i_character = sfImage_createFromFile(name);
    character->t_character = sfTexture_createFromImage(i_character, NULL);
    character->sp_character = sfSprite_create();
    character->sound = sfMusic_createFromFile("sound/Arrow.ogg");
    character->stat = malloc(sizeof(int*) * 5);
    if (!character->stat || !i_character || !character->t_character ||
        !character->sp_character || !character->sound)
        return;
    set_character2(character);
    set_character_stat(character, name);
    sfMusic_setVolume(character->sound, 50);
    sfSprite_setOrigin(character->sp_character, origin);
    sfSprite_setPosition(character->sp_character, character->pos);
    sfSprite_setTexture(character->sp_character, character->t_character,
    sfTrue);
    sfSprite_setTextureRect(character->sp_character, character->animation);
}

void move_character(game_t *game)
{
    int x = game->scene1->character->pos.x / 50;
    int y = game->scene1->character->pos.y / 50;

    if (!game->scene1->market_status) {
        left_character(game, x, y);
        right_character(game, x, y);
        up_character(game, x, y);
        down_character(game, x, y);
    }
    if (game->scene1->character->animation.left > 188)
        game->scene1->character->animation.left = 0;
    sfSprite_setTextureRect(game->scene1->character->sp_character,
    game->scene1->character->animation);
    sfSprite_setPosition(game->scene1->character->sp_character,
    game->scene1->character->pos);
    sfRenderWindow_drawSprite(game->window,
    game->scene1->character->sp_character, NULL);
}