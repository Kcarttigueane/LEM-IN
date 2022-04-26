/*
** EPITECH PROJECT, 2021
** LE-MIN
** File description:
** my_strcmp.c
*/

#include "lib.h"

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;

    if (s1 == NULL)
        return -1;
    for (; s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0'; i++);
    return s1[i] - s2[i];
}
