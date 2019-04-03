/*
** EPITECH PROJECT, 2018
** MUL_my_defender_2018
** File description:
** scene1.c
*/

#include "prototypes.h"

static void set_game2(scene1_t *scene1)
{
    fs_open_file(scene1->map, "map/map1.txt");
    fs_open_file(scene1->wall, "map/wall1.txt");
    set_shop(scene1->shop);
    set_hud(scene1);
    set_list_enemy(scene1->list_enemy[0], 220, 350);
    set_list_enemy(scene1->list_enemy[1], 490, 1030);
    set_list_enemy(scene1->list_enemy[2], 1100, 730);
    scene1->nbr_enemy = 18;
    scene1->list_ally = NULL;
    scene1->sound = sfMusic_createFromFile("sound/Enemy_Dies.ogg");
    sfMusic_setVolume(scene1->sound, 50);
}

void set_game(scene1_t *scene1)
{
    scene1->map = malloc(sizeof(map_t));
    scene1->wall = malloc(sizeof(map_t));
    scene1->character = malloc(sizeof(character_t));
    scene1->list_enemy = malloc(sizeof(list_enemy_t*) * 3);
    scene1->list_ally = malloc(sizeof(list_ally_t));
    scene1->weapon = malloc(sizeof(weapon_t));
    scene1->shop = malloc(sizeof(shop_t));
    if (!scene1->map || !scene1->wall || !scene1->character ||
        !scene1->list_enemy || !scene1->list_ally ||
        !scene1->weapon || !scene1->shop)
        return;
    for (int i = 0; i < 3; i++) {
        scene1->list_enemy[i] = malloc(sizeof(list_enemy_t));
        if (!scene1->list_enemy[i])
            return;
    }
    set_game2(scene1);
}