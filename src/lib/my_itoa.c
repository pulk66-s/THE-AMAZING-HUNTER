/*
** EPITECH PROJECT, 2020
** DuckHunt
** File description:
** my_itoa.c
*/

#include <stdlib.h>

int power(int n, int p)
{
    int powered_n = n;

    if (p == 0) {
        return (1);
    } else {
        for (int i = 1 ; i < p ; i++) {
            powered_n *= n;
        }
    }
    return (powered_n);
}

static int nb_len(int nb)
{
    int len = 1;

    while (nb >= 10) {
        nb /= 10;
        len++;
    }
    return (len);
}

static int get_first_digit(int nb)
{
    while (nb >= 10) {
        nb /= 10;
    }
    return (nb);
}

char *my_itoa(int num)
{
    char *str = malloc(sizeof (char) * (nb_len(num) + 1));
    int i = 0;
    int len = nb_len(num);

    while (num > 0 || len > 0) {
        if (len == nb_len(num)) {
            str[i] = get_first_digit(num) + 48;
            num -= get_first_digit(num) * power(10, nb_len(num) - 1);
        } else {
            str[i] = '0';
        }
        len--;
        i++;
    }
    str[i] = '\0';
    return (str);
}