/*
** EPITECH PROJECT, 2020
** DuckHunt
** File description:
** struct.h
*/

#ifndef __STRUCT_H__
#define __STRUCT_H__

#include <SFML/Graphics.h>
#include <SFML/Audio.h>

typedef struct
{
    int top;
    int left;
    int width;
    int height;
    int frame;
    int nb_frame;
    float pos_x;
    float pos_y;
    int dead;
    float x_speed;
    int y_speed;
    int counted;
    int mode;
    char *texture_path;
    sfIntRect rect;
    sfTexture **texture;
    sfSprite *sprite;
    sfMusic *death_music;
} object_t;

typedef struct
{
    int top;
    int left;
    int width;
    int height;
} coor_t;

typedef struct
{
    int width;
    int height;
} screen_t;

typedef struct
{
    int x;
    int y;
    int anim;
    char *t;
    sfText *text;
} text_t;

typedef struct
{
    sfSprite **background;
    text_t play_text;
    float frame;
} start_menu_t;

typedef struct
{
    int x;
    int y;
    sfTexture *texture;
    sfSprite *sprite;
} hearth_t;

typedef struct
{
    int nb_obj;
    int life;
    sfRenderWindow *win;
    sfSprite *back;
} temp_t;

typedef struct
{
    text_t score;
    text_t highscore;
    hearth_t *hearths;
    sfSprite *cursor;
    int music;
} other_t;

typedef struct
{
    sfEvent event;
    sfRenderWindow *window;
} win_t;

typedef struct
{
    sfRenderWindow *window;
    sfSprite *background;
    int mode;
} back_t;

typedef struct
{
    int nb_bird;
    int mode;
    sfMusic **level_theme;
} temp2_t;

typedef struct
{
    int nb_obj;
    int mode;
} temp3_t;

#endif