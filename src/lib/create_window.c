/*
** EPITECH PROJECT, 2020
** DuckHunt
** File description:
** create_window.c
*/

#include <SFML/Window.h>
#include <SFML/Graphics.h>

sfRenderWindow *create_window(int w, int l, char *name)
{
    sfVideoMode mode = {w, l, 32};
    sfRenderWindow *window = sfRenderWindow_create(mode, name,
                                sfDefaultStyle, NULL);
    return (window);
}
