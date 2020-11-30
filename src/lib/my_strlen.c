/*
** EPITECH PROJECT, 2020
** DuckHunt
** File description:
** my_strlen.c
*/

int my_strlen(char *str)
{
    int l = 0;

    for (; str[l] != '\0' ; l++);
    return (l);
}