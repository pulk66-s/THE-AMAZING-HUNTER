/*
** EPITECH PROJECT, 2020
** DuckHunt
** File description:
** create_rect.c
*/

#include <SFML/Graphics.h>
#include "../include/struct.h"

sfIntRect create_rect(object_t obj)
{
    sfIntRect rect;

    rect.top = obj.top;
    rect.left = obj.left;
    rect.width = obj.width;
    rect.height = obj.height;
    return (rect);
}