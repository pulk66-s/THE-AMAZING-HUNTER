/*
** EPITECH PROJECT, 2020
** DuckHunt
** File description:
** my_strcmp.c
*/

int my_strcmp(char *s1, char *s2)
{
    int i = 0;
    int size;

    while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0') {
        i++;
    }
    size = s1[i] - s2[i];
    return (size);
}