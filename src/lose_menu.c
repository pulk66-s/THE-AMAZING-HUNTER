/*
** EPITECH PROJECT, 2020
** DuckHunt
** File description:
** lose_menu.c
*/

#include "include/duck_hunt.h"

static void lose_event(sfRenderWindow *win, sfMusic *music)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(win, &event)) {
        if (event.type == sfEvtClosed || sfKeyboard_isKeyPressed(sfKeyEscape)) {
            sfRenderWindow_close(win);
        }
        if (sfKeyboard_isKeyPressed(sfKeyReturn)) {
            sfMusic_destroy(music);
            sfRenderWindow_close(win);
            game_start();
        }
    }
}

void lose_menu(void)
{
    sfRenderWindow *window = create_window(1400, 900, "Lose Menu");
    sfSprite *back = create_sprite("img/game_over.jpg", 
                                    (coor_t){0, 0, 1400, 900});
    sfMusic *end_music = sfMusic_createFromFile("sound/game_over.ogg");
    sfSprite *game_over_text = create_sprite("img/game_over_text.png",
                                    (coor_t){0, 0, 1400, 900});

    sfSprite_setPosition(game_over_text, (sfVector2f){380, 600});
    sfMusic_play(end_music);
    while (sfRenderWindow_isOpen(window)) {
        lose_event(window, end_music);
        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_drawSprite(window, back, NULL);
        sfRenderWindow_drawSprite(window, game_over_text, NULL);
        sfRenderWindow_display(window);
    }
}