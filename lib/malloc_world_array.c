/*
** EPITECH PROJECT, 2021
** LE-MIN
** File description:
** malloc_world_array.c
*/

#include "lib.h"

int **malloc_world_int_array(int nb_rows, int nb_cols)
{
    int **world_array = malloc(sizeof(int *) * (nb_rows + 1));

    for (int i = 0; i < nb_rows; i++)
        world_array[i] = malloc(sizeof(int) * (nb_cols));

    for (int k = 0; k < nb_rows; k++)
        for (int j = 0; j < nb_cols; j++)
            world_array[k][j] = 0;
    world_array[nb_rows] = NULL;
    return world_array;
}

