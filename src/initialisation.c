/*
** EPITECH PROJECT, 2018
** file
** File description:
** filefile
*/

#include "prototypes.h"

static void game(game_t *st)
{
    st->scene0 = malloc(sizeof(scene0_t));
    st->scene1 = malloc(sizeof(scene1_t));
    st->scene2 = malloc(sizeof(scene2_t));
    st->scene3 = malloc(sizeof(scene3_t));
    st->scene4 = malloc(sizeof(scene4_t));
    if (!st->scene0 || !st->scene1 || !st->scene2 ||
        !st->scene3 || !st->scene4)
        return;
}

static void init_struct(game_t *st)
{
    set_menu(st->scene0);
    set_game(st->scene1);
    set_gameover(st->scene2);
    set_option(st->scene3);
    set_pause(st->scene4);
}

static void init_assets(game_t *st)
{
    st->scene = MENU;
    st->volume = 50;
    st->scene1->market_status = 0;
    st->chk = 0;
    st->scene1->hud->ult = 0;
    st->scene1->hud->speed = 10;
    st->clock = sfClock_create();
    if (!st->clock)
        return;
    rect_life_bar(st);
    rect_fire(st);
}

game_t *initialisation(void)
{
    game_t *st = malloc(sizeof(game_t));
    sfVideoMode mode = {WIN_WIDTH, WIN_HEIGHT, 32};

    if (!st)
        return (NULL);
    game(st);
    init_struct(st);
    init_assets(st);
    st->game_sound = sfMusic_createFromFile("sound/main_sound.ogg");
    sfMusic_setVolume(st->game_sound, st->volume);
    sfMusic_play(st->game_sound);
    sfMusic_setLoop(st->game_sound, sfTrue);
    st->window = sfRenderWindow_create(mode,
    "MyDefender", sfDefaultStyle, NULL);
    sfRenderWindow_setFramerateLimit(st->window, 60);
    return (st);
}
