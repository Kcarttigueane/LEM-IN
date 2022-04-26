/*
** EPITECH PROJECT, 2021
** LE-MIN
** File description:
** add_path.c
*/

#include "lib.h"
#include "lemin.h"

path_t *create_path_node(int *array_path, int path_number)
{
    path_t *new_path = malloc(sizeof(path_t));

    int g_cost = 0;
    for (; array_path[g_cost] != (-1); g_cost++);

    new_path->path_array = malloc(sizeof(int) * (g_cost));
    for (int j = 0; j < g_cost; j++)
        new_path->path_array[j] = array_path[j];

    new_path->path_number = path_number;
    new_path->g_cost = g_cost;
    new_path->next = NULL;
    new_path->halt = 0;
    return new_path;
}

void add_path_node(path_t **p_list, int *path_array, int path_number)
{
    path_t *new_path = create_path_node(path_array, path_number);

    if (*p_list == NULL) {
        *p_list = new_path;
        return;
    }
    path_t *tmp = *p_list;
    while (tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = new_path;
}

int get_len_sum_array(path_t **path_list)
{
    int len_sum = 0;
    path_t *tmp = *path_list;

    while (tmp != NULL) {
        len_sum += tmp->g_cost;
        tmp = tmp->next;
    }
    return len_sum;
}

void print_path_list(path_t **path_list)
{
    write(1, "\n\n", 2);
    if (*path_list == NULL)
        return;
    for (path_t *temp = *path_list; temp; temp = temp->next) {
        write(1, GREEN, SIZE_COLOUR);
        for (int i = 0; i < temp->g_cost; i++) {
            my_put_nbr(temp->path_array[i]);
            write(1, " ", 1);
        }
        write(1, "\n", 1);
        write(1, RESET, SIZE_RESET);
        my_put_nbr(temp->path_number);
        write(1, "\n", 1);
        my_put_nbr(temp->g_cost);
    }
    write(1, "\n\n", 2);
}

void free_path_list(path_t **path_list)
{
    if (*path_list == NULL)
        return;
    path_t *temp = *path_list;
    while (*path_list) {
        temp = *path_list;
        *path_list = (*path_list)->next;
        free_array(temp->path_array);
        free(temp);
    }
    *path_list = NULL;
}
