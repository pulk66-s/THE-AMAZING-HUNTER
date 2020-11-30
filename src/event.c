/*
** EPITECH PROJECT, 2020
** DuckHunt
** File description:
** event.c
*/

#include <SFML/Window.h>
#include <SFML/Graphics.h>
#include "include/struct.h"
#include <stdio.h>
#include "include/duck_hunt.h"

void mouse_management(win_t window, 
                    object_t *list, int nb_obj, other_t *other);

static int close_window(sfEvent event, sfRenderWindow *window)
{
    if (event.type == sfEvtClosed || sfKeyboard_isKeyPressed(sfKeyEscape)) {
        sfRenderWindow_close(window);
        return (0);
    }
    return (1);
}

int mode_management(object_t **list, temp_t *t, int mode)
{
    int temp = mode;

    if (sfKeyboard_isKeyPressed(sfKeyLeft))
        temp--;
    else if (sfKeyboard_isKeyPressed(sfKeyRight))
        temp++;
    temp = temp < 0 ? 6 : temp;
    temp = temp > 6 ? 0 : temp;
    return (temp);
}


int event(object_t **list, temp_t *t, other_t *other, int *mode)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(t->win, &event)) {
        if (close_window(event, t->win) == 0)
            return (84);
        *mode = mode_management(list, t, *mode);
        mouse_management((win_t){event, t->win}, *list, t->nb_obj, other);
    }
    return (t->life);
}