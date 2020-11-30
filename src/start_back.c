/*
** EPITECH PROJECT, 2020
** DuckHunt
** File description:
** start_back.c
*/

#include "include/duck_hunt.h"

sfSprite **create_start_back(void)
{
    sfSprite **sprites = malloc(sizeof (sfSprite *) * 3);
    sfIntRect rect = (sfIntRect){0, 0, 1400, 900};
    sfTexture **text = malloc(sizeof (sfTexture *) * 3);

    for (int i = 0 ; i < 3 ; i++, rect.left += 1400)
        text[i] = sfTexture_createFromFile("img/menu_back.png", &rect);
    for (int i = 0 ; i < 3 ; sprites[i] = sfSprite_create(), i++);
    for (int i = 0 ; i < 3 ; i++)
        sfSprite_setTexture(sprites[i], text[i], sfTrue);
    return (sprites);
}