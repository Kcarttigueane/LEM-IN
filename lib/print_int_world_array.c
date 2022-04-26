/*
** EPITECH PROJECT, 2021
** LE-MIN
** File description:
** print_int_world_array.c
*/

#include "lib.h"

void print_int_world_array(int **a, int nb_row, int cols)
{
    for (int i = 0; i < nb_row; i++) {
        for (int j = 0; j < cols; j++) {
            my_put_nbr(a[i][j]);
            write(1, " ", 1);
        }
        write(1, "\n", 1);
    }
}
