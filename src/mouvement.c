/*
** EPITECH PROJECT, 2018
** file
** File description:
** filefile
*/

#include "prototypes.h"
#include "macros.h"

int key_pressed(void)
{
    if (sfKeyboard_isKeyPressed(sfKeyZ))
        return (UP);
    if (sfKeyboard_isKeyPressed(sfKeyUp))
        return (UP);
    if (sfKeyboard_isKeyPressed(sfKeyQ))
        return (LEFT);
    if (sfKeyboard_isKeyPressed(sfKeyLeft))
        return (LEFT);
    if (sfKeyboard_isKeyPressed(sfKeyD))
        return (RIGHT);
    if (sfKeyboard_isKeyPressed(sfKeyRight))
        return (RIGHT);
    if (sfKeyboard_isKeyPressed(sfKeyS))
        return (DOWN);
    if (sfKeyboard_isKeyPressed(sfKeyDown))
        return (DOWN);
    return (10);
}