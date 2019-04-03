/*
** EPITECH PROJECT, 2018
** MUL_my_defender_2018
** File description:
** scene0.c
*/

#include "prototypes.h"

static void set_hud_position(scene1_t *scene1)
{
    sfVector2f pos = {1068.2, 796.4};
    sfVector2f pos_market = {1760.2, 1260.4};
    sfVector2f scale = {0.7, 0.7};
    sfVector2f scale2 = {1.0, 1};
    sfVector2f origin = {37.0, 115.0};
    sfVector2f fire_pos = {2000, 2000};

    for (int i = 0; i < NB_SPRITE_HUD - 3; i++) {
        sfSprite_setPosition(scene1->hud->t_hud[i]->sp_background, pos);
        sfSprite_setScale(scene1->hud->t_hud[i]->sp_background, scale);
    }
    for (int i = 9; i < NB_SPRITE_HUD; i++) {
        sfSprite_setPosition(scene1->hud->t_hud[i]->sp_background, pos_market);
        sfSprite_setScale(scene1->hud->t_hud[i]->sp_background, scale2);
    }
    sfSprite_setPosition(scene1->hud->t_hud[8]->sp_background, fire_pos);
    sfSprite_setOrigin(scene1->hud->t_hud[8]->sp_background, origin);
}

float calc_distance(game_t *game, float x, char c)
{
    sfVector2u window = sfRenderWindow_getSize(game->window);
    if (c == 'y')
        return ((x * window.y) / 1080);
    if (c == 'x')
        return ((x * window.x) / 1920);
    return (0);
}

static void set_hud2(scene1_t *scene1)
{
    set_background(scene1->hud->t_hud[SPRITE_MARKET], "hud/HUD4.png");
    set_hud_position(scene1);
    set_cheat(scene1);
    set_hud_text(scene1);
}

void set_hud(scene1_t *scene1)
{
    scene1->hud = malloc(sizeof(hud_t));
    scene1->hud->t_hud = malloc(sizeof(background_t*) * NB_SPRITE_HUD);
    if (!scene1->hud || !scene1->hud->t_hud)
        return;
    for (int i = 0; i < NB_SPRITE_HUD; i++) {
        scene1->hud->t_hud[i] = malloc(sizeof(background_t));
        if (!scene1->hud->t_hud[i])
            return;
    }
    set_background(scene1->hud->t_hud[0], "hud/HUD1.png");
    set_background(scene1->hud->t_hud[1], "hud/mage_hud.png");
    set_background(scene1->hud->t_hud[2], "hud/voleur_hud.png");
    set_background(scene1->hud->t_hud[3], "hud/chevalier_hud.png");
    set_background(scene1->hud->t_hud[4], "hud/ult_up.png");
    set_background(scene1->hud->t_hud[5], "hud/button_market.png");
    set_background(scene1->hud->t_hud[6], "hud/life.png");
    set_background(scene1->hud->t_hud[7], "hud/cheat.png");
    set_background(scene1->hud->t_hud[8], "hud/fire.png");
    set_background(scene1->hud->t_hud[9], "hud/arrow_shop.png");
    set_hud2(scene1);
}

void display_hud(game_t *game)
{
    sfRenderWindow_drawSprite(game->window,
    game->scene1->hud->t_hud[SPRITE_MARKET]->sp_background, NULL);
    if (game->scene1->character->stat[4] == 1)
        sfRenderWindow_drawSprite(game->window,
        game->scene1->hud->t_hud[SPRITE_ULT_HUD]->sp_background, NULL);
    if (game->scene0->p == 0)
        sfRenderWindow_drawSprite(game->window,
        game->scene1->hud->t_hud[SPRITE_THIEF_HUD]->sp_background, NULL);
    if (game->scene0->p == 1)
        sfRenderWindow_drawSprite(game->window,
        game->scene1->hud->t_hud[SPRITE_KNIGHT_HUD]->sp_background, NULL);
    if (game->scene0->p == 2)
        sfRenderWindow_drawSprite(game->window,
        game->scene1->hud->t_hud[SPRITE_WIZARD_HUD]->sp_background, NULL);
    render_life(game);
    sfRenderWindow_drawSprite(game->window,
    game->scene1->hud->t_hud[SPRITE_HUD]->sp_background, NULL);
    market(game);
    draw_cheat(game);
    modify_text(game);
}
