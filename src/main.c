/*
** EPITECH PROJECT, 2018
** file
** File description:
** description
*/

#include "prototypes.h"

static int is_help(char const *str)
{
    if (str[0] == '-') {
        if (str[1] == 'h' && !str[2])
            return (1);
        if (str[1] == '-' && str[2] == 'h' && str[3] == 'e' && str[4] == 'l' &&
        str[5] == 'p' && !str[6])
            return (1);
    }
    return (0);
}

int main(int ac, char **av)
{
    (void)av;
    float delta = 0;
    game_t *st = initialisation();

    if (ac == 2) {
        if (is_help(av[1]))
            st->scene = RULES;
    } else if (ac != 1)
        return (84);
    while (sfRenderWindow_isOpen(st->window)) {
        while (sfRenderWindow_pollEvent(st->window, &st->event))
            analyse_events(st);
        delta += sfClock_restart(st->clock).microseconds;
        if (delta > 100000) {
            render(st);
            delta -= 100000;
        }
    }
    //destroy_all(st);
    return (0);
}