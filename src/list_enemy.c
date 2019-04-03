/*
** EPITECH PROJECT, 2018
** MUL_my_defender_2018
** File description:
** list_enemy.c
*/

#include "prototypes.h"

static void set_number_enemy2(list_enemy_t *list_enemy, list_enemy_t *tmp)
{
    list_enemy->prev = tmp;
    list_enemy->next = NULL;
}

static void set_number_enemy(list_enemy_t *list_enemy, int x, int y)
{
    char *name1 = "enemy/little_orc.png";
    char *name2 = "enemy/little_orc2.png";
    int random;
    list_enemy_t *tmp = list_enemy;

    for (int i = 0; i < 5; i++) {
        list_enemy = list_enemy->next;
        list_enemy->first = malloc(sizeof(enemy_t));
        random = rand() % 4;
        if (random < 2)
            set_enemy(list_enemy->first, name1, x, y);
        else
            set_enemy(list_enemy->first, name2, x, y);
        list_enemy->next = malloc(sizeof(list_enemy_t));
        if (!list_enemy->first || !list_enemy->next)
            return;
        list_enemy->prev = tmp;
        tmp = list_enemy;
    }
    set_number_enemy2(list_enemy, tmp);
}

void set_list_enemy(list_enemy_t *list_enemy, int x, int y)
{
    char *name1 = "enemy/little_orc.png";
    char *name2 = "enemy/little_orc2.png";
    int random;

    random = rand() % 10;
    list_enemy->first = malloc(sizeof(enemy_t));
    if (!list_enemy->first)
        return;
    if (random < 5)
        set_enemy(list_enemy->first, name1, x, y);
    else
        set_enemy(list_enemy->first, name2, x, y);
    list_enemy->next = malloc(sizeof(list_enemy_t));
    if (!list_enemy->next)
        return;
    list_enemy->first->start = 1;
    list_enemy->prev = NULL;
    set_number_enemy(list_enemy, x, y);
}

static int move_list_enemy2(game_t *game, int j)
{
    if (j >= 100 && game->scene1->nbr_enemy <= 20) {
        add_list_enemy(game->scene1->list_enemy[0], 220, 350);
        add_list_enemy(game->scene1->list_enemy[1], 490, 1030);
        add_list_enemy(game->scene1->list_enemy[2], 1100, 730);
        game->scene1->nbr_enemy += 3;
        j = 0;
    }
    return (j);
}

game_t *move_list_enemy(game_t *game, int x)
{
    static int i = 0;
    static int j = 0;
    list_enemy_t *list = game->scene1->list_enemy[x];

    if (list == NULL || list->first == NULL)
        return (game);
    for (; list->next != NULL && list->first->start == 1; list = list->next)
        move_enemy(list->first, game);
    if (!game->scene1->market_status) {
        if (i == 20) {
            list->first->start = 1;
            i = 0;
        }
        j = move_list_enemy2(game, j);
        i++;
        j++;
    }
    return (game);
}