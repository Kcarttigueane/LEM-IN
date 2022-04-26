/*
** EPITECH PROJECT, 2021
** LE-MIN
** File description:
** print_array.c
*/

#include "lib.h"
#include "bonus.h"

void print_array(int *array, char *color)
{
    if (array == NULL)
        return;
    if (color != NULL)
        write(1, CYAN, SIZE_COLOUR);
    for (int i = 0; array[i] != (-1); i++) {
        my_put_nbr(array[i]);
        write(1, " ", 1);
    }
    write(1, RESET, SIZE_RESET);
    write(1, "\n", 1);
}
