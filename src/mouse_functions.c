/*
** EPITECH PROJECT, 2018
** bistro graphical bonus
** File description:
** bonus
*/

#include "prototypes.h"

sfVector2f get_mouse_pos(sfRenderWindow *window)
{
    sfVector2i mouse_pos2i;

    mouse_pos2i = sfMouse_getPositionRenderWindow(window);
    if (mouse_pos2i.y < 0)
        mouse_pos2i.y = 0;
    if (mouse_pos2i.x < 0)
        mouse_pos2i.x = 0;
    return ((sfVector2f){mouse_pos2i.x, mouse_pos2i.y});
}