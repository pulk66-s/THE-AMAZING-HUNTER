/*
** EPITECH PROJECT, 2020
** DuckHunt
** File description:
** clean.c
*/

#include "include/duck_hunt.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

char *isole_nb(char *str)
{
    char *result = malloc(sizeof (char) * 100);
    int i = 0;
    int c = 0;

    for (; !(str[i] >= '0' && str[i] <= '9') ; i++);
    for (; str[i] >= '0' && str[i] <= '9' && str[i] != '\0' ; 
        result[c] = str[i], i++, c++);
    result[c] = '\0';
    return (result);
}

int clean_all(object_t **list, int nb_bird, other_t other, int mode)
{
    FILE *fd = fopen("score", "w");
    char *text = my_itoa(my_getnbr(isole_nb(other.score.t)));
    fprintf(fd, "%s", text);

    for (int i = 0 ; i < nb_bird ; i++) {
        for (int j = 0 ; j < (*list)[i].nb_frame ; j++)
            sfTexture_destroy((*list)[i].texture[j]);
        sfSprite_destroy((*list)[i].sprite);
        sfMusic_destroy((*list)[i].death_music);
    }
    fclose(fd);
    return (mode);
}