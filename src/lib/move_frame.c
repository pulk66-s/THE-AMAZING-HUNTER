/*
** EPITECH PROJECT, 2020
** DuckHunt
** File description:
** move_frame.c
*/

#include <SFML/Graphics.h>

void move_frame(sfIntRect *obj_rect, int offset, int max_value)
{
    obj_rect->left += offset;
    if (obj_rect->left >= max_value) {
        obj_rect->left = 0;
    }
}