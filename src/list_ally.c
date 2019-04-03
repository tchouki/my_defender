/*
** EPITECH PROJECT, 2018
** MUL_my_defender_2018
** File description:
** list_ally.c
*/

#include "prototypes.h"

void set_list_ally(list_ally_t *list_ally, int x, int y, char *name)
{
    list_ally->first = malloc(sizeof(ally_t));
    if (!list_ally->first)
        return;
    set_ally(list_ally->first, name, x, y);
    list_ally->next = malloc(sizeof(list_ally_t));
    if (!list_ally->next)
        return;
    list_ally->prev = NULL;
    list_ally->next = NULL;
}

static void add_list_ally2(list_ally_t *list_ally, int x, int y, char *name)
{
    list_ally_t *tmp;

    for (; list_ally->next != NULL; list_ally = list_ally->next);
    list_ally->next = malloc(sizeof(list_ally_t));
    if (!list_ally->next)
        return;
    tmp = list_ally;
    list_ally = list_ally->next;
    list_ally->first = malloc(sizeof(ally_t));
    if (!list_ally->first)
        return;
    set_ally(list_ally->first, name, x, y);
    list_ally->prev = tmp;
    list_ally->next = NULL;
}

void add_list_ally(list_ally_t *list_ally, int x, int y, char *name)
{
    if (list_ally == NULL) {
        list_ally = malloc(sizeof(list_ally_t));
        if (!list_ally)
            return;
        list_ally->first = malloc(sizeof(ally_t));
        if (!list_ally->first)
            return;
        set_ally(list_ally->first, name, x, y);
        list_ally->next = malloc(sizeof(list_ally_t));
        if (!list_ally->next)
            return;
        list_ally->prev = malloc(sizeof(list_ally_t));
        if (!list_ally->prev)
            return;
        list_ally->next = NULL;
        list_ally->prev = NULL;
    } else {
        add_list_ally2(list_ally, x, y, name);
    }
}

list_ally_t *kill_ally(list_ally_t *list_ally, int nbr)
{
    if (list_ally == NULL)
        return (NULL);
    if (list_ally->next == NULL && list_ally->prev == NULL)
        return (NULL);
    for (int i = 0; i < nbr &&
        list_ally->next != NULL; i++, list_ally = list_ally->next);
    if (list_ally->prev == NULL) {
        list_ally->next->prev = NULL;
        list_ally = list_ally->next;
        list_ally->prev = NULL;
    } else if (list_ally->next == NULL) {
        list_ally->prev->next = NULL;
        list_ally = list_ally->prev;
        list_ally->next = NULL;
    } else {
        list_ally = list_ally->prev;
        list_ally->next->next->prev = list_ally;
        list_ally->next = list_ally->next->next;
    }
    return (list_ally);
}

game_t *move_list_ally(game_t *game)
{
    static int i = 0;
    list_ally_t *list = game->scene1->list_ally;

    if (game->scene1->list_ally == NULL)
        return (game);
    for (; list->next != NULL; list = list->next)
        move_ally(list->first, game);
    move_ally(list->first, game);
    if (!game->scene1->market_status) {
        if (i == 20) {
            list->first->start = 1;
            i = 0;
        }
        i++;
    }
    return (game);
}