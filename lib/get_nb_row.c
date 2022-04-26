/*
** EPITECH PROJECT, 2021
** LE-MIN
** File description:
** get_nb_row.c
*/

#include "lib.h"

int get_nb_row(char **map)
{
    int i = 0;
    for (; map[i]; i++);
    return i;
}
