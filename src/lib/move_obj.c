/*
** EPITECH PROJECT, 2020
** DuckHunt
** File description:
** move_obj.c
*/

#include <SFML/Graphics.h>
#include "../include/struct.h"

void move_obj(object_t *obj, int x, int y)
{
    sfVector2f pos = sfSprite_getPosition(obj->sprite);
    sfVector2f c = {pos.x + x * obj->x_speed, pos.y + y * obj->y_speed};

    sfSprite_setPosition(obj->sprite, c);
    obj->pos_x = c.x;
    obj->pos_y = c.y;
}