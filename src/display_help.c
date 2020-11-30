/*
** EPITECH PROJECT, 2020
** DuckHunt
** File description:
** display_help.c
*/

#include <unistd.h>

static void my_putstr(char *str)
{
    for (int i = 0 ; str[i] != '\0' ; i++) {
        write(1, &str[i], 1);
    }
}

int display_help(void)
{
    my_putstr("How to play ?\n\n");
    my_putstr("Control : \n");
    my_putstr("You must kill the ducks with the mouse by clicking on them\n");
    my_putstr("If you don't like the graphics, you can change them with");
    my_putstr(" the left and right arrow,\n");
    my_putstr("All the mode :\n-1 : Classic Hunter\n-2 : Mario Bros Hunter");
    my_putstr("\n-3 : Jew Vs Registeel\n-4 : Uganda Knuckles\n-5 : \
retro & nyan-cat");
    my_putstr("\n-6 : PEPE\n-7 : JEAN MICHEL CRAPAUD!\n");
    return (0);
}