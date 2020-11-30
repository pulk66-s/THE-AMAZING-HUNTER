/*
** EPITECH PROJECT, 2020
** DuckHunt
** File description:
** create_text.c
*/

#include "include/duck_hunt.h"

void update_text(text_t *text)
{
    sfColor color = sfText_getColor(text->text);

    color.a += text->anim * 5;
    if (color.a >= 250)
        text->anim = -1;
    if (color.a <= 5)
        text->anim = 1;
    sfText_setColor(text->text, color);
}

text_t create_text(char *path, screen_t s, char *str, int size)
{
    text_t t = {0};
    sfFont *font = sfFont_createFromFile(path);
    sfText *text = sfText_create();

    sfText_setFont(text, font);
    sfText_setPosition(text, (sfVector2f){s.width, s.height});
    sfText_setString(text, str);
    sfText_setCharacterSize(text, size);
    sfText_setColor(text, (sfColor){0, 0, 0, 255});
    t.anim = -1;
    t.text = text;
    t.x = s.width;
    t.y = s.height;
    return (t);
}
