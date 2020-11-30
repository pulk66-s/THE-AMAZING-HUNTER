/*
** EPITECH PROJECT, 2020
** DuckHunt
** File description:
** update_object.c
*/

#include <stdlib.h>
#include "../include/struct.h"
#include "../include/duck_hunt.h"
#include <stdio.h>

void move_frame(sfIntRect *obj_rect, int offset, int max_value);

sfTexture **change_texture2(sfTexture **text, int mode, int speedx)
{
    sfIntRect rect = (sfIntRect){0, 0, 110, 110};
    sfTexture **texture = malloc(sizeof (sfTexture *) * 3);

    if (mode == 5)
        texture = create_texture(speedx > 0 ? "img/SJW.png" : 
                "img/reverse_SJW.png", rect, 3, 110);
    if (mode == 6)
        texture = create_texture(speedx > 0 ? "img/lamasticot.png" : 
                "img/reverse_lamasticot.png", rect, 3, 110);
}

sfTexture **change_texture(sfTexture **text, int mode, int speedx)
{
    sfIntRect rect = (sfIntRect){0, 0, 110, 110};
    sfTexture **texture = malloc(sizeof (sfTexture *) * 3);

    if (mode == 0)
        texture = create_texture(speedx > 0 ? "img/bird.png" : 
                "img/reverse_bird.png", rect, 3, 110);
    if (mode == 1)
        texture = create_texture(speedx > 0 ? "img/bill_ball.png" :
                 "img/reverse_bill_ball.png", rect, 3, 110);
    if (mode == 2)
        texture = create_texture(speedx > 0 ? "img/reverse_registeel.png" :
                 "img/registeel.png", rect, 3, 110);
    if (mode == 3)
        texture = create_texture(speedx > 0 ? "img/uganda.png" :
                 "img/reverse_uganda.png", rect, 3, 110);
    if (mode == 4)
        texture = create_texture(speedx > 0 ? "img/nyan.png" :
                 "img/reverse_nyan.png", rect, 3, 110);
    return (mode > 4 ? change_texture2(text, mode, speedx) : texture);
}

void update_object(object_t *obj, int nb_frame, int *life, int mode)
{
    move_frame(&obj->rect, obj->width, obj->width * nb_frame);
    if (mode != obj->mode) {
        obj->texture = change_texture(obj->texture, mode, obj->x_speed);
        obj->mode = mode;
    }
    sfSprite_setTexture(obj->sprite, obj->texture[obj->frame], sfFalse);
    obj->frame = (obj->frame + 1) % nb_frame;
    if (obj->x_speed > 0) {
        if (obj->pos_x > 1400) {
            obj->dead = 1;
            *life = obj->counted == 0 ? (*life) - 1 : (*life);
            obj->counted = 1;
        }
    } else {
        if (obj->pos_x < -110) {
            obj->dead = 1;
            (*life) = obj->counted == 0 ? (*life) - 1 : (*life);
            obj->counted = 1;
        }
    }
}