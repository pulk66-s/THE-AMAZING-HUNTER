/*
** EPITECH PROJECT, 2020
** DuckHunt
** File description:
** draw_obj.c
*/

#include "../include/struct.h"

void draw_obj(object_t obj, sfRenderWindow *window)
{
    sfRenderWindow_drawSprite(window, obj.sprite, NULL);
}