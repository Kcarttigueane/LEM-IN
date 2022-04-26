/*
** EPITECH PROJECT, 2021
** LE-MIN
** File description:
** my_atoi.c
*/

#include "lib.h"

int my_atoi(char *str)
{
    long value = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (!(str[i] >= '0' && str[i] <= '9'))
            return (-1);
        value = value * 10 + (str[i] - 48);
        if (value > 2147483647 || value < -2147483647)
            return (-1);
    }
    return value;
}
