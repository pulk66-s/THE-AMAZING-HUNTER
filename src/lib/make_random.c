/*
** EPITECH PROJECT, 2020
** DuckHunt
** File description:
** make_random.c
*/

#include <time.h>
#include <stdlib.h>

int make_random(int lower, int upper)
{    
    int random = (rand() % (upper - lower + 1)) + lower;
    return (random);
}
