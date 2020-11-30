/*
** EPITECH PROJECT, 2020
** DuckHunt
** File description:
** create_hearths.c
*/

#include "include/struct.h"
#include "include/duck_hunt.h"
#include <stdlib.h>

hearth_t create_hearth(int x, int y)
{
    hearth_t hearth = {0};

    hearth.texture = sfTexture_createFromFile("img/hearth.png", NULL);
    hearth.sprite = sfSprite_create();
    sfSprite_setTexture(hearth.sprite, hearth.texture, sfTrue);
    hearth.x = x;
    hearth.y = y;
    sfSprite_setPosition(hearth.sprite, (sfVector2f){x, y});
    return (hearth);
}

hearth_t *create_hearths(void)
{
    hearth_t *hearts = malloc(sizeof (object_t) * 5);
    hearth_t heart;

    for (int i = 0 ; i < 5 ; i++) {
        heart = create_hearth(1100 + (i + 1) * 40, 0);
        hearts[i] = heart;
    }
    return (hearts);
}