/*
** EPITECH PROJECT, 2021
** LE-MIN
** File description:
** my_strncpy.c
*/

#include "lib.h"

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;

    for (i = 0; i < n && src[i] != '\0'; i++)
        dest[i] = src[i];
    for (; i < n; i++)
        dest[i] = '\0';
    return dest;
}
