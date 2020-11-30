/*
** EPITECH PROJECT, 2020
** DuckHunt
** File description:
** create_other.c
*/

#include "include/struct.h"
#include "include/duck_hunt.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

char *get_string(void)
{
    FILE *file = fopen("score", "r");
    char *buff = malloc(sizeof (char) * 100);
    int nb;

    fread(buff, 100, 100, file);
    nb = my_getnbr(isole_nb(buff));
    return (my_strcat("Score : ", my_itoa(nb)));
}

text_t get_score(void)
{
    text_t t;
    sfFont *font = sfFont_createFromFile("font/Verona.otf");
    sfText *text = sfText_create();

    t.x = 0;
    t.y = 0;
    t.anim = 0;
    sfText_setFont(text, font);
    t.t = get_string();
    sfText_setString(text, t.t);
    sfText_setCharacterSize(text, 32);
    sfText_setPosition(text, (sfVector2f){0, 0});
    sfText_setColor(text, (sfColor){0, 0, 0, 255});
    t.text = text;
    return (t);
}

char *get_highstring(void)
{
    FILE *file = fopen("highscore", "r");
    char *buff = malloc(sizeof (char) * 100);
    int nb;

    fread(buff, 100, 100, file);
    nb = my_getnbr(isole_nb(buff));
    return (my_strcat("HighScore : ", my_itoa(nb)));
}

text_t get_highscore(void)
{
    text_t t;
    sfFont *font = sfFont_createFromFile("font/Verona.otf");
    sfText *text = sfText_create();

    t.x = 0;
    t.y = 0;
    t.anim = 0;
    sfText_setFont(text, font);
    t.t = get_highstring();
    sfText_setString(text, t.t);
    sfText_setCharacterSize(text, 32);
    sfText_setPosition(text, (sfVector2f){0, 30});
    sfText_setColor(text, (sfColor){0, 0, 0, 255});
    t.text = text;
    return (t);
}

other_t create_other(int mode)
{
    other_t other;
    
    other.hearths = create_hearths();
    other.score = get_score();
    other.highscore = get_highscore();
    other.cursor = create_sprite("img/cursor.png", (coor_t){0, 0, 1400, 900});
    other.music = mode;
    return (other);
}