/*
** EPITECH PROJECT, 2017
** prototype.h
** File description:
** Protoypes
*/

#ifndef _PROTOTYPES_H_
    #define _PROTOTYPES_H_

    #include "struct.h"
    #include "macros.h"

//ally.c
void set_ally(ally_t *ally, char *name, int x, int y);
void move_ally(ally_t *first, game_t *game);

//background.c
void set_background(background_t *background, char *str);

//character.c
void set_character(character_t *character, char *name);
void move_character(game_t *game);

//cheat.c
void set_cheat(scene1_t *scene1);
void draw_cheat(game_t *game);

//destroy.c
void destroy_all(game_t *game);

//draw_ground.c
void choose_sprite_ground(game_t *game, int i, int j);

//draw_map.c
void solo(game_t *game);
void draw_wall(game_t *game);

//draw_wall.c
void choose_sprite_wall(game_t *game, int i, int j);

//draw_wallback.c
void choose_sprite_wall_back(game_t *game, int i, int j);

//enemy.c
void set_enemy(enemy_t *enemy, char *name, int x, int y);
void enemy_attack(enemy_t *first, game_t *game);
void move_enemy(enemy_t *first, game_t *game);

//event.c
void analyse_events(game_t *st);

//game.c
void play_scene0(game_t *game);
void play_scene1(game_t *game);
void play_scene2(game_t *game);
void play_scene3_4(game_t *game);
//hud.c
void set_hud(scene1_t *scene1);
float calc_distance(game_t *game, float x, char c);
void display_hud(game_t *game);

//hud_text.c
void set_hud_text(scene1_t *scene1);
void modify_text(game_t *game);

//initialisation.c
game_t *initialisation(void);

//life.c
void rect_life_bar(game_t *st);
void render_life(game_t *st);

//list_ally.c
void set_list_ally(list_ally_t *list_ally, int x, int y, char *name);
void add_list_ally(list_ally_t *list_ally, int x, int y, char *name);
list_ally_t *kill_ally(list_ally_t *list_ally, int nbr);
game_t *move_list_ally(game_t *game);

//list_enemy.c
void set_list_enemy(list_enemy_t *list_enemy, int x, int y);
game_t *move_list_enemy(game_t *game, int x);

//list_enemy_kill.c
void add_list_enemy(list_enemy_t *list_enemy, int x, int y);
list_enemy_t *kill_enemy(list_enemy_t *list_enemy, int nbr, game_t *game);

//main.c
int main(int ac, char **av);

//market.c
void market(game_t *st);

//mouse_functions.c
sfVector2f get_mouse_pos(sfRenderWindow *window);

//mouse_hovering.c
int mouse_hovering(game_t *st, sfSprite *sprite);

//mouvement.c
int key_pressed(void);

//mouvement_ally.c
int left_ally(ally_t *first, int random, game_t *game);
int right_ally(ally_t *first, int random, game_t *game);
int up_ally(ally_t *first, int random, game_t *game);
int down_ally(ally_t *first, int random, game_t *game);

//mouvement_character.c
void left_character(game_t *game, int x, int y);
void right_character(game_t *game, int x, int y);
void up_character(game_t *game, int x, int y);
void down_character(game_t *game, int x, int y);

//mouvement_enemy.c
int left_enemy(enemy_t *first, game_t *game, int x, int y);
int right_enemy(enemy_t *first, game_t *game, int x, int y);
int up_enemy(enemy_t *first, game_t *game, int x, int y);
int down_enemy(enemy_t *first, game_t *game, int x, int y);

//my_putnbr.c
char *my_put_nbr(int nbr);

//open_map.c
void fs_open_file(map_t *map, char *file);

//render.c
void render(game_t *st);

//scene0.c
void set_menu(scene0_t *scene0);
void display_scene0(game_t *game);

//scene1.c
void set_game(scene1_t *scene1);

//scene2.c
void set_gameover(scene2_t *scene2);
void display_scene2(game_t *game);

//scene3.c
void set_option(scene3_t *scene3);
void display_scene3(game_t *game);

//scene4.c
void set_pause(scene4_t *scene4);
void display_scene4(game_t *game);

//shop.c
void set_shop(shop_t *shop);
void display_shop(game_t *game);

//shop_item.c
void choose_item(game_t *game, sfVector2f pos, int market_status);
void see_money_item(game_t *game, sfVector2f pos, int market_status);

//spike.c
game_t *attack_ally(game_t *game, int x);
game_t *add_ally(game_t *game, int i, int j);

//trap.c
void place_trap(game_t *game);
void choose_sprite_trap(game_t *game, int i, int j);

//trap_effect.c
game_t *check_all_trap(game_t *game, int x);

//ultimate.c
game_t *config_ultimate(game_t *game);

//weapon.c
void set_weapon(weapon_t *weapon, char *name);
game_t *attack_weapon(game_t *game, int x);
void move_weapon2(game_t *game);
void move_weapon(game_t *game);

//wizard.c
void rect_fire(game_t *st);
game_t *render_ult_wizard(game_t *st);

#endif /* _PROTOTYPES_H_ */
