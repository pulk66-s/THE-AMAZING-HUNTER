/*
** EPITECH PROJECT, 2020
** DuckHunt
** File description:
** get_src.c
*/

char *get_src(int mode)
{
    switch (mode) {
    case 0:
        return ("img/background.png");
    case 1:
        return ("img/mario_background.png");
    case 2:
        return ("img/juif_background.png");
    case 3:
        return ("img/sonic_background.png");
    case 4:
        return ("img/retro.png");
    case 5:
        return ("img/PEPE.png");
    case 6:
        return ("img/crapaud_back.png");
    default:
        return ("img/background.png");
    }
}