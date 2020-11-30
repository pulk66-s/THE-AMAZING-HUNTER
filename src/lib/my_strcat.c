/*
** EPITECH PROJECT, 2020
** DuckHunt
** File description:
** my_strcat.c
*/

#include <stdlib.h>

int my_strlen(char *str);

char *my_strcat(char *s1, char *s2)
{
    char *result = malloc(sizeof (char) * my_strlen(s1) + my_strlen(s2) + 1);
    int c = 0;

    for (int i = 0 ; s1[i] != '\0' ; i++, c++) {
        result[c] = s1[i];
    }
    for (int j = 0 ; s2[j] != '\0' ; j++, c++) {
        result[c] = s2[j];
    }
    result[c] = '\0';
    return (result);
}