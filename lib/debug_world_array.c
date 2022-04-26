/*
** EPITECH PROJECT, 2021
** LE-MIN
** File description:
** debug_world_array.c
*/

#include "lib.h"
#include "bonus.h"

void debug_world_array(char **world)
{
    if (world == NULL)
        return;
    for (int i = 0; world[i] != NULL; i++) {
        write(1, "world[", 7);
        write(1, RED, SIZE_COLOUR);
        my_put_nbr(i);
        write(1, RESET, SIZE_RESET);
        write(1, "] = |", 5);
        write(1, YELLOW, SIZE_COLOUR);
        write(1, world[i], my_strlen(world[i]));
        write(1, RESET, SIZE_RESET);
        write(1, "|\n", 2);
    }
    write(1, "\n", 1);
}
