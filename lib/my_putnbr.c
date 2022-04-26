/*
** EPITECH PROJECT, 2021
** LE-MIN
** File description:
** my_putnbr.c
*/

#include "lib.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

void my_put_nbr(int nb)
{
    if (nb < 0) {
        write(1, "-", 1);
        nb *= -1;
    }
    if (nb >= 10)
        my_put_nbr(nb / 10);
    my_putchar(nb % 10 + 48);
}

