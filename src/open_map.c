/*
** EPITECH PROJECT, 2018
** MUL_my_defender_2018
** File description:
** open_map.c
*/

#include "prototypes.h"

static void set_sprite(map_t *map)
{
    sfImage *i_map;

    i_map = sfImage_createFromFile("map/bloc.png");
    map->t_map = sfTexture_createFromImage(i_map, NULL);
    map->sp_map = sfSprite_create();
    if (!i_map || !map->t_map || !map->sp_map)
        return;
    map->animation.left = 0;
    map->animation.top = 0;
    map->animation.height = 50;
    map->animation.width = 50;
    sfSprite_setTexture(map->sp_map, map->t_map, sfTrue);
    sfSprite_setTextureRect(map->sp_map, map->animation);
}

static char **put_2d_tab(char **tab, char *buf, int size, int sizelign)
{
    int x = 0;
    int y = 0;

    tab = malloc(size * sizeof(char *));
    if (!tab)
        return (NULL);
    for (int j = 0; j < size; j++)
        tab[j] = malloc(sizeof(char) * sizelign + 2);
    for (int i = 0; buf[i] != '\0'; i++)
        if (buf[i] == '\n') {
            tab[x][y] = '\n';
            tab[x][y + 1] = '\0';
            y = 0;
            x++;
        } else {
            tab[x][y] = buf[i];
            y++;
        }
    tab[x] = NULL;
    return (tab);
}

void fs_open_file(map_t *map, char *file)
{
    int fd;
    int ret;
    char buf[BUFFSIZE];
    int size = 0;
    int sizelign = 0;
    set_sprite(map);

    fd = open(file, O_RDONLY);
    ret = read(fd, buf, BUFFSIZE);
    for (int i = 0; buf[i] != '\0'; i++)
        if (buf[i] == '|')
            size++;
    for (int i = 0; buf[i] != '|'; i++, sizelign++);
    close(fd);
    map->tab = put_2d_tab(map->tab, buf, size, sizelign);
}