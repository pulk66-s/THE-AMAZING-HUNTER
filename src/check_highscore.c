/*
** EPITECH PROJECT, 2020
** DuckHunt
** File description:
** check_highscore.c
*/

#include "include/duck_hunt.h"
#include <stdio.h>
#include <stdlib.h>

void check_highscore(void)
{
    FILE *score_f = fopen("score", "r");
    FILE *highscore_f = fopen("highscore", "r");
    int score;
    int highscore;
    char *buff = malloc(sizeof (char) * 100);

    fread(buff, 100, 100, score_f);
    score = my_getnbr(isole_nb(buff));
    fread(buff, 100, 100, highscore_f);
    highscore = my_getnbr(isole_nb(buff));
    if (score > highscore) {
        highscore_f = fopen("highscore", "w");
        fwrite(isole_nb(my_itoa(score)), my_strlen(isole_nb(my_itoa(score))),
                 my_strlen(isole_nb(my_itoa(score))), highscore_f);
    }
    score_f = fopen("score", "w");
    fwrite("0", 1, 1, score_f);
}