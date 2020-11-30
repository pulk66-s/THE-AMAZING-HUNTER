/*
** EPITECH PROJECT, 2020
** DuckHunt
** File description:
** create_coor.c
*/

#include "../include/struct.h"

coor_t create_coor(int top, int left, int width, int height)
{
    coor_t c;

    c.top = top;
    c.left = left;
    c.width = width;
    c.height = height;
    return (c);
}