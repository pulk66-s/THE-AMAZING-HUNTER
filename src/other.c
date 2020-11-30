/*
** EPITECH PROJECT, 2020
** DuckHunt
** File description:
** other.c
*/

#include "include/struct.h"
#include "include/duck_hunt.h"
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <stdlib.h>

void draw_other(sfRenderWindow *win, other_t other, int life)
{
    sfRenderWindow_drawText(win, other.score.text, NULL);
    sfRenderWindow_drawText(win, other.highscore.text, NULL);
    sfRenderWindow_drawSprite(win, other.cursor, NULL);
    for (int i = 0 ; i < life ; i++) {
        sfRenderWindow_drawSprite(win, other.hearths[i].sprite, NULL);
    }
}

sfSprite *change_back(int mode)
{
    sfSprite *sprite = create_sprite(get_src(mode), (coor_t){0, 0, 1400, 900});

    return (sprite);
}

void update_other(other_t *other, sfRenderWindow *window, back_t *back, 
                    int mode)
{
    int nb = my_getnbr(isole_nb(other->score.t));
    sfVector2i pos = sfMouse_getPositionRenderWindow(window);

    if (back->mode != mode) {
        back->background = change_back(mode);
        back->mode = mode;
    }
    other->score.t = my_strcat("Score : ", my_itoa(nb));
    sfSprite_setPosition(other->cursor, (sfVector2f){pos.x - 10, pos.y - 10});
    sfText_setString(other->score.text, other->score.t);
}