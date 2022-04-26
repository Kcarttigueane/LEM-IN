/*
** EPITECH PROJECT, 2021
** LE-MIN
** File description:
** my_str_is_num.c
*/

#include "lib.h"
#include "lemin.h"

int my_str_is_num(char *str)
{
    for (int i = 0; str[i]; i++)
        if (!(str[i] >= '0' && str[i] <= '9'))
            return 1;
    return SUCCESS;
}
