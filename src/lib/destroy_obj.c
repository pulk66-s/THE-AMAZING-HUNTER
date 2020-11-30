/*
** EPITECH PROJECT, 2020
** DuckHunt
** File description:
** destroy_obj.c
*/

#include "../include/struct.h"
#include <stdlib.h>

void destroy_obj(object_t *obj)
{
    obj->dead = 1;
    obj->counted = 1;
}