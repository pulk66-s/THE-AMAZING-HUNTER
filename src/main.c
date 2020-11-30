/*
** EPITECH PROJECT, 2020
** DuckHunt
** File description:
** main.c
*/

#include "include/start.h"
#include "include/duck_hunt.h"

void event_menu(sfRenderWindow *win, sfMusic *music)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(win, &event)) {
        if (event.type == sfEvtClosed || sfKeyboard_isKeyPressed(sfKeyEscape)) {
            sfMusic_destroy(music);
            sfRenderWindow_close(win);
        }
        if (sfKeyboard_isKeyPressed(sfKeyReturn) == sfTrue) {
            sfMusic_destroy(music);
            sfRenderWindow_close(win);
            game_start();
        }
    }
}

void display(sfRenderWindow *win, start_menu_t *objs, sfClock **clock)
{
    sfTime time = sfClock_getElapsedTime(*clock);

    sfRenderWindow_clear(win, sfBlack);
    sfRenderWindow_drawSprite(win, objs->background[(int)objs->frame], NULL);
    sfRenderWindow_drawText(win, objs->play_text.text, NULL);
    sfRenderWindow_display(win);
    objs->frame = objs->frame >= 2.8 ? 0 : objs->frame + 0.2;
    sfClock_restart(*clock);
}

sfSprite *create_sprite(char *path, coor_t coor)
{
    sfIntRect rect = {coor.left, coor.top, coor.width, coor.height};
    sfTexture *texture = sfTexture_createFromFile(path, &rect);
    sfSprite *sprite = sfSprite_create();

    sfSprite_setTexture(sprite, texture, sfTrue);
    return (sprite);
}

static sfMusic *get_music(void)
{
    sfMusic *music = sfMusic_createFromFile("sound/xenogenesis.ogg");

    sfMusic_setLoop(music, sfTrue);
    return (music);
}

int help(int argc, char **argv)
{
    if (argc > 1)
        if (my_strcmp(argv[1], "-h") == 0)
            return (display_help());
    return (1);
}

int main(int argc, char **argv)
{
    sfRenderWindow *win;
    start_menu_t objs = {0};
    sfMusic *music;
    sfClock *clock = sfClock_create();

    if (help(argc, argv) == 0)
        return (0);
    win = create_window(1400, 900, "Main Menu");
    objs.background = create_start_back();
    objs.play_text = create_text("font/Verona.otf", (screen_t){450, 450}, 
                                        "Press Enter to play", 64);
    music = get_music();
    sfMusic_play(music);
    while (sfRenderWindow_isOpen(win)) {
        event_menu(win, music);
        update_text(&objs.play_text);
        display(win, &objs, &clock);
    }
    return (0);
}