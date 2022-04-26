/*
** EPITECH PROJECT, 2021
** DANTE_STAR
** File description:
** dequeue.c
*/

#include "lib.h"
#include "lemin.h"

int *dequeue(node_t **front, node_t **rear)
{
    if ((*front == NULL) && (*rear == NULL)) {
        write(1, "[dequeue] : can't dequeue empty queue\n", 36);
        return NULL;
    }
    node_t *temp = *front;
    node_t *save = malloc(sizeof(node_t));
    save->path_array = (*front)->path_array;
    (*front) = (*front)->next;
    if ((*front) == NULL)
        *rear = NULL;
    else {
        free(temp);
        temp = NULL;
    }
    return save->path_array;
}
