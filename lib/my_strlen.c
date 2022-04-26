/*
** EPITECH PROJECT, 2021
** LE-MIN
** File description:
** my_strlen.c
*/

#include "lib.h"

int my_strlen(char *str)
{
    int i = 0;
    for (; str[i]; i++);
    return i;
}

int get_len_delimiter(char *str, char end_point)
{
    int i = 0;
    if (str == NULL)
        return ERROR;
    for (; str[i] != end_point; i++)
        if (str[i] == '\0')
            return ERROR;
    return i;
}
