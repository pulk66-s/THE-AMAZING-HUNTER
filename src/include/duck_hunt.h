/*
** EPITECH PROJECT, 2020
** DuckHunt
** File description:
** duck_hunt.h
*/

#ifndef __DUCK_HUNT_H__
#define __DUCK_HUNT_H__

#include "struct.h"

int event(object_t **list, temp_t *a, other_t *other, int *mode);
sfRenderWindow *create_window(int w, int l, char *name);
coor_t create_coor(int top, int left, int width, int height);
object_t create_object(coor_t coor, char **texture, int nb_frame, int r);
void draw_obj(object_t obj, sfRenderWindow *window);
void move_frame(sfIntRect *obj_rect, int offset, int max_value);
sfMusic **set_loop(int nb, sfMusic **music);
sfMusic **create_music(void);
void update_object(object_t *obj, int nb_frame, int *life, int mode);
char *get_src(int mode);
int my_strcmp(char *s1, char *s2);
void move_obj(object_t *obj, int x, int y);
object_t *init_obj(int nb_obj, screen_t screen_size, int mode);
void draw(back_t back, object_t *objs, int *life, temp3_t t);
int clean_all(object_t **list, int nb_bird, other_t other, int mode);
void draw_other(sfRenderWindow *win, other_t other, int life);
void update_other(other_t *other, sfRenderWindow *window, back_t *b, int mode);
int my_getnbr(char const *str);
char *get_src_zero(int mode);
char *get_src_one(int mode);
sfTexture **create_texture(char *path, sfIntRect rect, 
                                int nb_frame, int f_size);
sfSprite *create_sprite(char *path, coor_t coor);
back_t get_back(int mode);
text_t create_text(char *path, screen_t s, char *str, int size);
char *my_itoa(int n);
char *my_strcat(char *s1, char *s2);
int game_start(void);
int my_strlen(char *str);
char *isole_nb(char *str);
void check_highscore(void);
void lose_menu(void);
hearth_t *create_hearths(void);

#endif