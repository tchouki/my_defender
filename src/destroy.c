/*
** EPITECH PROJECT, 2018
** MUL_my_defender_2018
** File description:
** character.c
*/

#include "prototypes.h"

static void destroy_all5(game_t *game)
{
    for (int i = 0; i < 3; i++) {
        sfSprite_destroy(game->scene4->list_background[i]->sp_background);
        sfTexture_destroy(game->scene4->list_background[i]->t_background);
    }
    sfText_destroy(game->scene3->text);
    for (int i = 0; i < 8; i++) {
        sfSprite_destroy(game->scene3->list_background[i]->sp_background);
        sfTexture_destroy(game->scene3->list_background[i]->t_background);
        free(game->scene3->list_background[i]);
    }
    free(game->scene3->list_background);
    free(game->scene3);
    sfText_destroy(game->scene2->text);
    for (int i = 0; i < 3; i++) {
        sfSprite_destroy(game->scene2->list_background[i]->sp_background);
        sfTexture_destroy(game->scene2->list_background[i]->t_background);
        free(game->scene2->list_background[i]);
    }
    free(game->scene2->list_background);
    free(game->scene2);
}

static void destroy_all4(game_t *game)
{
    free(game->scene4->list_background);
    for (int i = 0; i < 8; i++) {
        sfSprite_destroy(game->scene0->list_background[i]->sp_background);
        sfTexture_destroy(game->scene0->list_background[i]->t_background);
        free(game->scene0->list_background[i]);
    }
    free(game->scene0->list_background);
    free(game->scene0);
    sfSprite_destroy(game->scene1->shop->background->sp_background);
    sfTexture_destroy(game->scene1->shop->background->t_background);
    free(game->scene1->shop->background);
    free(game->scene1->shop);
    sfSprite_destroy(game->scene1->weapon->sp_weapon);
    sfTexture_destroy(game->scene1->weapon->t_weapon);
    free(game->scene1->weapon);
    for (int i = 0; i < NB_SPRITE_HUD; i++) {
        sfSprite_destroy(game->scene1->hud->t_hud[i]->sp_background);
        sfTexture_destroy(game->scene1->hud->t_hud[i]->t_background);
        free(game->scene1->hud->t_hud[i]);
    }
}

static void destroy_all3(game_t *game)
{
    free(game->scene4);
    free(game->scene1->hud->t_hud);
    for (int i = 0; i < 3; i++)
        sfText_destroy(game->scene1->hud->text[i]);
    free(game->scene1->hud);
    sfMusic_destroy(game->scene1->sound);
    sfSprite_destroy(game->scene1->character->sp_character);
    sfTexture_destroy(game->scene1->character->t_character);
    sfMusic_destroy(game->scene1->character->sound);
    free(game->scene1->character);
    for (int i = 0; i < 3; i++) {
        for (; game->scene1->list_enemy[i]->next != NULL;
            game->scene1->list_enemy[i] = game->scene1->list_enemy[i]->next) {
            sfSprite_destroy(game->scene1->list_enemy[i]->first->sp_enemy);
            sfTexture_destroy(game->scene1->list_enemy[i]->first->t_enemy);
            free(game->scene1->list_enemy[i]->first);
        }
        free(game->scene1->list_enemy[i]);
    }
    free(game->scene1->list_enemy);
}

static void destroy_all2(game_t *game)
{
    if (game->scene1->list_ally != NULL) {
        for (; game->scene1->list_ally->next != NULL; game->scene1->list_ally =
            game->scene1->list_ally->next) {
            sfSprite_destroy(game->scene1->list_ally->first->sp_ally);
            sfTexture_destroy(game->scene1->list_ally->first->t_ally);
            free(game->scene1->list_ally->first);
        }
        free(game->scene1->list_ally);
    }
    for (int i = 0; game->scene1->map->tab[i] != NULL; i++)
        free(game->scene1->map->tab[i]);
    free(game->scene1->map->tab);
    sfSprite_destroy(game->scene1->map->sp_map);
    sfTexture_destroy(game->scene1->map->t_map);
    free(game->scene1->map);
    for (int i = 0; game->scene1->wall->tab[i] != NULL; i++)
        free(game->scene1->wall->tab[i]);
    free(game->scene1->wall->tab);
}

void destroy_all(game_t *game)
{
    destroy_all5(game);
    destroy_all4(game);
    destroy_all3(game);
    destroy_all2(game);
    sfSprite_destroy(game->scene1->wall->sp_map);
    sfTexture_destroy(game->scene1->wall->t_map);
    free(game->scene1->wall);
    free(game->scene1);
    sfMusic_destroy(game->game_sound);
    free(game->time);
    sfClock_destroy(game->clock);
    sfRenderWindow_destroy(game->window);
    free(game);
}