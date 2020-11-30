/*
** EPITECH PROJECT, 2020
** DuckHunt
** File description:
** init_obj_list.c
*/

#include "include/struct.h"
#include <stdlib.h>

int make_random(int lower, int upper);
object_t create_object(coor_t coordinate, char **texture, int nb_frame, int r);
coor_t create_coor(int top, int left, int width, int height);

char *get_src_zero(int mode)
{
    switch (mode) {
    case 0:
        return ("img/bird.png");
    case 1:
        return ("img/bill_ball.png");
    default:
        return ("img/bird.png");
    }
}

char *get_src_one(int mode)
{
    switch (mode) {
    case 0:
        return ("img/reverse_bird.png");
    case 1:
        return ("img/reverse_bill_ball.png");
    default:
        return ("img/reverse_bird.png");
    }
}

object_t *init_obj(int nb_obj, screen_t screen_size, int mode)
{
    int r;
    object_t *obj = malloc(sizeof (object_t) * nb_obj);
    char **src = malloc(sizeof (char *) * 2);

    src[0] = get_src_zero(mode);
    src[1] = get_src_one(mode);
    for (int i = 0 ; i < nb_obj ; i++) {
        r = make_random(0, 10) * 55;
        obj[i] = create_object(create_coor(0, 0, 110, 110), src, 3, r);
    }
    return (obj);
}
