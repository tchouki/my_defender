/*
** EPITECH PROJECT, 2018
** file
** File description:
** filefile
*/

#include "prototypes.h"

int mouse_hovering(game_t *st, sfSprite *sprite)
{
    sfFloatRect sprite_rect = sfSprite_getGlobalBounds(sprite);

    if (get_mouse_pos(st->window).x >= sprite_rect.left &&
    get_mouse_pos(st->window).x <= sprite_rect.left +
    sprite_rect.width && get_mouse_pos(st->window).y >=
    sprite_rect.top && get_mouse_pos(st->window).y <=
    sprite_rect.top + sprite_rect.height)
        return (1);
    return (0);
}