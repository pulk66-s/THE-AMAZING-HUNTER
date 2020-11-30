/*
** EPITECH PROJECT, 2020
** DuckHunt
** File description:
** create_obj.c
*/

#include <SFML/Audio.h>
#include <stdlib.h>
#include "../include/struct.h"

sfIntRect create_rect(object_t obj);
void move_frame(sfIntRect *obj_rect, int offset, int max_value);
int make_random(int lower, int upper);

sfTexture **create_texture(char *path, sfIntRect rect, 
                                int nb_frame, int f_size)
{
    sfTexture **texture = malloc(sizeof (*texture) * nb_frame);
    sfTexture *temp;

    for (int i = 0 ; i < nb_frame ; i++, rect.left += f_size) {
        temp = sfTexture_createFromFile(path, &rect);
        texture[i] = temp;
    }
    return (texture);
}

void get_changement(object_t *obj)
{
    sfSprite_setPosition(obj->sprite, (sfVector2f){obj->pos_x, obj->pos_y});
    sfSprite_setTexture(obj->sprite, obj->texture[0], sfFalse);
}

int make_x(int speed)
{
    int random;

    if (speed == 1) {
        random = make_random(0, 5) * -50;
    } else {
        random = make_random(0, 5) * 50 + 1400;
    }
    return (random);
}

object_t create_object(coor_t coordinate, char **texture, int nb_frame, int r)
{
    object_t obj = {0};

    obj.top = coordinate.top;
    obj.left = coordinate.left;
    obj.width = coordinate.width;
    obj.height = coordinate.height;
    obj.x_speed = make_random(0, 1) == 1 ? 1 : -1;
    obj.y_speed = 1;
    obj.mode = 0;
    obj.pos_x = make_x(obj.x_speed);
    obj.pos_y = r;
    obj.nb_frame = nb_frame;
    obj.rect = create_rect(obj);
    obj.texture_path = obj.x_speed > 0 ? texture[0] : texture[1];
    obj.texture = create_texture(obj.texture_path, obj.rect, obj.nb_frame, obj.width);
    obj.sprite = sfSprite_create();
    obj.death_music = sfMusic_createFromFile("sound/hit.ogg");
    get_changement(&obj);
    return (obj);
}