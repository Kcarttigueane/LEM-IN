/*
** EPITECH PROJECT, 2021
** LE-MIN
** File description:
** my_str_is_alpha_num.c
*/

#include "lib.h"

int my_str_is_alpha_num(char *str)
{
    if (str == NULL)
        return ERROR;
    for (int i = 0; str[i]; i++) {
        if (!(str[i] >= 'a' && str[i] <= 'z')
        && !(str[i] >= 'A' && str[i] <= 'Z')
        && !(str[i] >= '0' && str[i] <= '9'))
            return 1;
    }
    return SUCCESS;
}
