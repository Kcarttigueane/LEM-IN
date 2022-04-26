/*
** EPITECH PROJECT, 2021
** LE-MIN
** File description:
** my_strcpy.c
*/

#include "lib.h"

char *my_strcpy(char *dest, char const *src)
{
    int i;

    for (i = 0; src[i]; i++) {
        if (src[i] == '\n')
            break;
        dest[i] = src[i];
    }
    dest[i] = '\0';
    return dest;
}
