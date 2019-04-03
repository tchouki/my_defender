/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** draw_map.c
*/

#include "prototypes.h"

static game_t *enemy_on_spike(game_t *game, int x, int i, int j)
{
    list_enemy_t *tmp = game->scene1->list_enemy[x];

    for (int pos = 0; tmp->next != NULL; tmp = tmp->next, pos++)
        if (tmp->first->pos.x - 50 <= j * 50 &&
            tmp->first->pos.x + 25 >= j * 50 &&
            tmp->first->pos.y - 50 <= i * 50 &&
            tmp->first->pos.y + 25 >= i * 50) {
            game->scene1->list_enemy[x] =
        kill_enemy(game->scene1->list_enemy[x], pos - 1, game);
            game->scene1->map->tab[i][j] = 'o';
        }
    return (game);
}

static game_t *kill_spike(game_t *game, int x, int i, int j)
{
    static int limit = 0;

    if (game->scene1->list_enemy[x] != NULL &&
        game->scene1->map->tab[i][j] == '1')
        game = enemy_on_spike(game, x, i, j);
    if (game->scene1->map->tab[i][j] == '2')
        limit++;
    if (game->scene1->map->tab[i][j] == '2' && limit >= 10 &&
        !game->scene1->market_status) {
        game->scene1->shop->coins++;
        limit = 0;
    }
    return (game);
}

static game_t *check_potion(game_t *game, int i, int j)
{
    int x_c = game->scene1->character->pos.x;
    int y_c = game->scene1->character->pos.y;

    if (game->scene1->map->tab[i][j] == '3') {
        if (x_c - 50 <= j * 50 && x_c + 25 >= j * 50 &&
            y_c - 50 <= i * 50 && y_c + 25 >= i * 50) {
            game->scene1->character->stat[0] += 20;
            game->scene1->map->tab[i][j] = 'o';
        }
    }
    if (game->scene1->map->tab[i][j] == '4') {
        if (x_c - 50 <= j * 50 && x_c + 25 >= j * 50 &&
            y_c - 50 <= i * 50 && y_c + 25 >= i * 50) {
            game->scene1->character->stat[4] = 1;
            game->scene1->map->tab[i][j] = 'o';
        }
    }
    return (game);
}

game_t *check_all_trap(game_t *game, int x)
{
    for (int i = 0; game->scene1->map->tab[i] != NULL; i++)
        for (int j = 0; game->scene1->map->tab[i][j] != '|'; j++) {
            game = kill_spike(game, x, i, j);
            game = add_ally(game, i, j);
            game = check_potion(game, i , j);
        }
    game = attack_ally(game, x);
    return (game);
}