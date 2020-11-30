/*
** EPITECH PROJECT, 2020
** DuckHunt
** File description:
** main.c
*/

#include <SFML/Window.h>
#include <SFML/Graphics.h>
#include <SFML/System/Clock.h>
#include <stdlib.h>
#include <stdio.h>
#include "include/duck_hunt.h"
#include "include/struct.h"
#include <time.h>
#include <SFML/Audio.h>

other_t create_other(int mode);

screen_t get_size(int w, int l)
{
    screen_t s_size;

    s_size.width = w;
    s_size.height = l;
    return (s_size);
}

int nb_alive(object_t *list, int nb)
{
    int alive = 0;

    for (int i = 0 ; i < nb ; i++) {
        if (list[i].dead == 0) {
            alive++;
        }
    }
    return (alive);
}

back_t get_back(int mode)
{
    back_t b;
    sfIntRect i;
    sfTexture *t;
    sfSprite *sprite;

    i.top = 0;
    i.left = 0;
    i.width = 1400;
    i.height = 900;
    t = sfTexture_createFromFile(get_src(mode), &i);
    sprite = sfSprite_create();
    sfSprite_setTexture(sprite, t, sfFalse);
    b.background = sprite;
    b.mode = 0;
    return (b);
}

int game(sfRenderWindow *window, sfTime time_c, int *life, temp2_t t)
{
    object_t *list = init_obj(t.nb_bird, get_size(1400, 900 * 0.67), t.mode);
    sfClock *clock = sfClock_create();
    other_t other = create_other(t.mode);
    back_t b = get_back(t.mode);

    while (sfRenderWindow_isOpen(window)) {
        time_c = sfClock_getElapsedTime(clock);
        if (other.music != t.mode) {
            sfMusic_stop(t.level_theme[other.music]);
            sfMusic_play(t.level_theme[t.mode]);
            other.music = t.mode;
        }
        if (time_c.microseconds / 1000000.0 > 0.05) {
            update_other(&other, window, &b, t.mode);
            sfRenderWindow_clear(window, sfBlack);
            draw((back_t){window, b.background, t.mode}, list, life, 
                (temp3_t){t.nb_bird, t.mode});
            draw_other(window, other, *life);
            *life = event(&list, &(temp_t){t.nb_bird, *life, window
                        , b.background}, &other, &(t.mode));
            sfClock_restart(clock);
            sfRenderWindow_display(window);
        }
        if (nb_alive(list, t.nb_bird) == 0 || *life == 84)
            break;
    }
    return (*life == 84 ? 0 : clean_all(&list, t.nb_bird, other, t.mode));
}

int game_start(void)
{
    sfRenderWindow *window = create_window(1400, 900, "AMAZING HUNTER");
    sfTime time_c;
    int life = 5;
    int mode = 0;
    int music = mode;
    sfMusic **level_theme = create_music();
    sfMusic *theme = sfMusic_createFromFile("sound/level_theme.ogg");

    sfMusic_setLoop(level_theme[mode], sfTrue);
    sfMusic_play(level_theme[mode]);
    sfRenderWindow_setMouseCursorVisible(window, sfFalse);
    srand(time(NULL));
    for (int nb_bird = 1 ; life >= 1  && life != 84 ; nb_bird++)
        mode = game(window, time_c, &life, (temp2_t){
                            nb_bird, mode, level_theme});
    if (life != 84) {
        sfMusic_destroy(level_theme[mode]);
        lose_menu();
    }
    check_highscore();
    return (0);
}