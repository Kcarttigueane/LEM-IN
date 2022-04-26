/*
** EPITECH PROJECT, 2021
** LE-MIN
** File description:
** free_array.c
*/

#include "lib.h"
#include "lemin.h"

void free_array(int *array)
{
    if (array == NULL)
        return;
    free(array);
}
