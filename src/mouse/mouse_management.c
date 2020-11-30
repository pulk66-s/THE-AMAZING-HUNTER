/*
** EPITECH PROJECT, 2020
** DuckHunt
** File description:
** mouse_management.c
*/

#include <SFML/Window.h>
#include <SFML/Graphics.h>
#include <stdio.h>
#include "../include/struct.h"
#include "../include/duck_hunt.h"
#include <SFML/Audio.h>

void destroy_obj(object_t *obj);

void check_kill(sfVector2i pos, object_t *list, int nb_obj, other_t *other)
{
    int n;
    sfVector2f t_pos;

    for (int i = 0 ; i < nb_obj ; i++) {
        t_pos = sfSprite_getPosition(list[i].sprite);
        if (pos.x > t_pos.x && pos.x < t_pos.x + list[i].width &&
            pos.y > t_pos.y && pos.y < t_pos.y + list[i].height) {
            destroy_obj(&list[i]);
            n = my_getnbr(isole_nb(other->score.t)) + 10;
            other->score.t = my_strcat("Score : ", my_itoa(n));
            sfText_setString(other->score.text, other->score.t);
        }
    }
}

void mouse_management(win_t window, object_t *list,
                    int nb_obj, other_t *other)
{
    if (window.event.type == sfEvtMouseButtonPressed &&
    sfMouse_isButtonPressed(sfMouseLeft)) {
        sfVector2i pos = sfMouse_getPositionRenderWindow(window.window);
        check_kill(pos, list, nb_obj, other);
        sfMusic_play(list[0].death_music);
    }
}