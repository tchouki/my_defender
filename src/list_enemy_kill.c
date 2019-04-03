/*
** EPITECH PROJECT, 2018
** MUL_my_defender_2018
** File description:
** list_enemy.c
*/

#include "prototypes.h"

static void add_list_enemy_notempty(list_enemy_t *list_enemy, int x, int y)
{
    int random;
    list_enemy_t *tmp;

    for (; list_enemy->next != NULL; list_enemy = list_enemy->next);
    list_enemy->next = malloc(sizeof(list_enemy_t));
    tmp = list_enemy;
    list_enemy = list_enemy->next;
    list_enemy->first = malloc(sizeof(enemy_t));
    if (!list_enemy->first)
        return;
    random = rand() % 10;
    if (random < 5)
        set_enemy(list_enemy->first, "enemy/little_orc.png", x, y);
    else if (random > 5 && random < 7)
        set_enemy(list_enemy->first, "enemy/big_orc.png", x, y);
    else
        set_enemy(list_enemy->first, "enemy/little_orc2.png", x, y);
    list_enemy->prev = tmp;
    list_enemy->next = NULL;
}

void add_list_enemy(list_enemy_t *list_enemy, int x, int y)
{
    char *name1 = "enemy/little_orc.png";
    char *name2 = "enemy/little_orc2.png";
    int random;

    if (list_enemy == NULL) {
        random = rand() % 10;
        list_enemy = malloc(sizeof(list_enemy_t));
        list_enemy->first = malloc(sizeof(enemy_t));
        if (random < 5)
            set_enemy(list_enemy->first, name1, x, y);
        else
            set_enemy(list_enemy->first, name2, x, y);
        list_enemy->next = NULL;
        list_enemy->prev = NULL;
    } else
        add_list_enemy_notempty(list_enemy, x, y);
}

static list_enemy_t *kill_enemy2(list_enemy_t *list_enemy)
{
    if (list_enemy->prev == NULL) {
        list_enemy = list_enemy->next;
        list_enemy->prev = NULL;
    } else if (list_enemy->next == NULL) {
        list_enemy = list_enemy->prev;
        list_enemy->next = NULL;
    } else {
        list_enemy = list_enemy->prev;
        list_enemy->next->next->prev = list_enemy;
        list_enemy->next = list_enemy->next->next;
    }
    return (list_enemy);
}

list_enemy_t *kill_enemy(list_enemy_t *list_enemy, int nbr, game_t *game)
{
    sfMusic_stop(game->scene1->sound);
    if (list_enemy == NULL)
        return (NULL);
    if (list_enemy->next == NULL && list_enemy->prev == NULL)
        return (NULL);
    for (int i = 0; i < nbr && list_enemy->next != NULL &&
        list_enemy->first != NULL; i++, list_enemy = list_enemy->next);
    sfMusic_play(game->scene1->sound);
    game->scene1->character->kill++;
    game->scene1->shop->coins += 10;
    list_enemy = kill_enemy2(list_enemy);
    game->scene1->nbr_enemy--;
    return (list_enemy);
}