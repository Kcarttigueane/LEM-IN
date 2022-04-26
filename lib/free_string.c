/*
** EPITECH PROJECT, 2021
** LE-MIN
** File description:
** free_string.c
*/

#include "lib.h"

void free_string(char *str)
{
    if (str == NULL)
        return;
    free(str);
}
