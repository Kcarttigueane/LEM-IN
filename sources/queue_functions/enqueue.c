/*
** EPITECH PROJECT, 2021
** DANTE_STAR
** File description:
** enqueue.c
*/

#include "lib.h"
#include "lemin.h"

void enqueue(node_t **front, node_t **rear, int *array, int size_array)
{
    node_t *new = malloc(sizeof(node_t));
    if (new == NULL)
        return;
    new->path_array = malloc(sizeof(int) * (size_array + 1));
    for (int i = 0; i <= size_array; i++)
        new->path_array[i] = -1;
    for (int j = 0; array[j] != (-1); j++)
        new->path_array[j] = array[j];
    new->next = NULL;
    if ((*front == NULL) && (*rear == NULL)) {
        (*front) = new;
        (*rear) = new;
        return;
    }
    (*rear)->next = new;
    (*rear) = new;
}
