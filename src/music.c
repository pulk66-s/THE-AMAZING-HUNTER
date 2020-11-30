/*
** EPITECH PROJECT, 2020
** DuckHunt
** File description:
** music.c
*/

#include "include/duck_hunt.h"

sfMusic **set_loop(int nb, sfMusic **music)
{
    for (int i = 0 ; i < nb ; i++) {
        sfMusic_setLoop(music[i], sfTrue);
    }
    return (music);
}

sfMusic **create_music(void)
{
    sfMusic **music = malloc(sizeof (sfMusic *) * 7);

    music[0] = sfMusic_createFromFile("sound/level_theme.ogg");
    music[1] = sfMusic_createFromFile("sound/mario_theme.ogg");
    music[2] = sfMusic_createFromFile("sound/thune_music.ogg");
    music[3] = sfMusic_createFromFile("sound/uganda.ogg");
    music[4] = sfMusic_createFromFile("sound/fat_rat.ogg");
    music[5] = sfMusic_createFromFile("sound/PEPE.ogg");
    music[6] = sfMusic_createFromFile("sound/crapaud.ogg");
    music = set_loop(7, music);
    return (music);
}