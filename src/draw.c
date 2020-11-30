/*
** EPITECH PROJECT, 2020
** DuckHunt
** File description:
** draw.c
*/

#include <SFML/Graphics.h>
#include "include/struct.h"

void draw_obj(object_t obj, sfRenderWindow *window);
void move_obj(object_t *obj, int x, int y);
void update_object(object_t *obj, int nb_frame, int *life, int mode);

void draw(back_t back, object_t *objs, int *life, temp3_t t)
{
    for (int i = 0 ; i < t.nb_obj ; i++) {
        update_object(&(objs[i]), 3, life, t.mode);
        move_obj(&(objs[i]), 10, 0);
    }
    sfRenderWindow_drawSprite(back.window, back.background, NULL);
    for (int i = 0 ; i < t.nb_obj ; i++) {
        if (objs[i].dead == 0)
            draw_obj(objs[i], back.window);
    }
}