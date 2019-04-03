/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** draw_map.c
*/

#include "prototypes.h"

static game_t *ally_on_enemy(game_t *game, int x, list_ally_t *tmpa, int j)
{
    int x_c = tmpa->first->pos.x;
    int y_c = tmpa->first->pos.y;
    list_enemy_t *tmp = game->scene1->list_enemy[x];

    for (int i = 0; tmp->next != NULL; tmp = tmp->next, i++)
        if (x_c - 25 <= tmp->first->pos.x && x_c + 25 >= tmp->first->pos.x &&
            y_c - 25 <= tmp->first->pos.y && y_c + 25 >= tmp->first->pos.y) {
            game->scene1->list_enemy[x] =
            kill_enemy(game->scene1->list_enemy[x], i - 1, game);
            game->scene1->list_ally = kill_ally(game->scene1->list_ally, j - 1);
        }
    return (game);
}

game_t *attack_ally(game_t *game, int x)
{
    list_enemy_t *tmp = game->scene1->list_enemy[x];
    list_ally_t *tmpa = game->scene1->list_ally;


    if (tmp != NULL && tmpa != NULL) {
        game = ally_on_enemy(game, x, tmpa, 0);
        for (int j = 0; tmpa->next != NULL; tmpa = tmpa->next, j++)
            game = ally_on_enemy(game, x, tmpa, j);
    }
    return (game);
}

game_t *add_ally(game_t *game, int i, int j)
{
    char *skeleton = "ally/skeleton.png";
    char *wizard = "ally/wizard.png";

    if (game->scene1->map->tab[i][j] == '5') {
        if (game->scene1->list_ally == NULL) {
            game->scene1->list_ally = malloc(sizeof(list_ally_t));
            set_list_ally(game->scene1->list_ally, j * 50, i * 50, skeleton);
        } else
            add_list_ally(game->scene1->list_ally, j * 50, i * 50, skeleton);
        game->scene1->map->tab[i][j] = 'o';
    }
    if (game->scene1->map->tab[i][j] == '6') {
        if (game->scene1->list_ally == NULL) {
            game->scene1->list_ally = malloc(sizeof(list_ally_t));
            set_list_ally(game->scene1->list_ally, j * 50, i * 50, wizard);
        } else
            add_list_ally(game->scene1->list_ally, j * 50, i * 50, wizard);
        game->scene1->map->tab[i][j] = 'o';
    }
    return (game);
}