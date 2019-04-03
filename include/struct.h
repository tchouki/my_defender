/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** my_defender.h
*/

#ifndef MY_H_
    #define MY_H_

    #include <stdio.h>
    #include <unistd.h>
    #include <stdlib.h>
    #include <stddef.h>
    #include <math.h>
    #include <SFML/Audio.h>
    #include <SFML/Graphics.h>
    #include <SFML/System/Export.h>
    #include <SFML/System/Time.h>
    #include <SFML/System/Types.h>
    #include <fcntl.h>

    #define BUFFSIZE 965

typedef struct background {
    sfTexture *t_background;
    sfSprite *sp_background;
} background_t;

typedef struct map {
    char **tab;
    sfTexture *t_map;
    sfSprite *sp_map;
    sfIntRect animation;
} map_t;

typedef struct shop {
    background_t *background;
    sfIntRect animation;
    int item;
    unsigned int coins;
} shop_t;

typedef struct enemy {
    sfTexture *t_enemy;
    sfSprite *sp_enemy;
    sfIntRect animation;
    sfVector2f pos;
    int start;
    int hp;
} enemy_t;

typedef struct list_enemy {
    enemy_t *first;
    struct list_enemy *next;
    struct list_enemy *prev;
} list_enemy_t;

typedef struct ally {
    sfTexture *t_ally;
    sfSprite *sp_ally;
    sfIntRect animation;
    sfVector2f pos;
    int start;
    int hp;
} ally_t;

typedef struct list_ally {
    ally_t *first;
    struct list_ally *next;
    struct list_ally *prev;
} list_ally_t;

typedef struct character {
    sfTexture *t_character;
    sfSprite *sp_character;
    sfIntRect animation;
    sfVector2f pos;
    sfMusic *sound;
    unsigned short int *stat;
    int kill;
} character_t;

typedef struct weapon {
    sfTexture *t_weapon;
    sfSprite *sp_weapon;
    sfVector2f pos;
    int attack;
    float angle;
    int kill;
} weapon_t;

typedef struct hud {
    sfIntRect life;
    sfIntRect fire;
    unsigned short int ult;
    unsigned short int speed;
    background_t **t_hud;
    sfText **text;
} hud_t;

typedef struct scene4 {
    background_t **list_background;
} scene4_t;

typedef struct scene3 {
    background_t **list_background;
    sfText *text;
} scene3_t;

typedef struct scene2 {
    background_t **list_background;
    sfText *text;
} scene2_t;

typedef struct scene1 {
    int market_status;
    int nbr_enemy;
    map_t *map;
    map_t *wall;
    character_t *character;
    hud_t *hud;
    weapon_t *weapon;
    shop_t *shop;
    list_enemy_t **list_enemy;
    list_ally_t *list_ally;
    sfMusic *sound;
} scene1_t;

typedef struct scene0 {
    background_t **list_background;
    int swap;
    int p;
} scene0_t;

typedef struct game {
    sfEvent event;
    sfRenderWindow *window;
    sfMouseButton button;
    sfMouseMoveEvent mouseMove;
    sfClock *clock;
    sfTime *time;
    sfMusic *game_sound;
    unsigned int chk;
    int scene;
    int volume;
    scene0_t *scene0;
    scene1_t *scene1;
    scene2_t *scene2;
    scene3_t *scene3;
    scene4_t *scene4;
} game_t;

#endif
