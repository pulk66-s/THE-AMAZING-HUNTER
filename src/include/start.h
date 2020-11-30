/*
** EPITECH PROJECT, 2020
** DuckHunt
** File description:
** start.h
*/

#ifndef __START_H__
#define __START_H__

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include "struct.h"


sfRenderWindow *create_window(int w, int l, char *name);
coor_t create_coor(int top, int left, int width, int height);
int game_start(void);
int display_help(void);
text_t create_text(char *path, screen_t s, char *str, int size);
void update_text(text_t *text);
sfSprite **create_start_back(void);

#endif