/*
** EPITECH PROJECT, 2021
** LE-MIN
** File description:
** free_int_world_array.c
*/

#include "lib.h"
#include "lemin.h"

void free_int_world_array(int **array, int row)
{
    if (array == NULL)
        return;
    for (int i = 0; i < row; i++)
        free(array[i]);
    free(array);
}
