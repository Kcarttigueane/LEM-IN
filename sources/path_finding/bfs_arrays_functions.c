/*
** EPITECH PROJECT, 2021
** B-CPE-200-LYN-2-1-lemin-tom.desalmand
** File description:
** bfs_arrays_functions.c
*/

#include "lib.h"
#include "lemin.h"

int get_last_index(int *array)
{
    int i = 0;
    if (array == NULL || array[0] == -1)
        return -1;
    for (; array[i + 1] != (-1); i++);
    return i;
}

int is_in_array(int *array, int i, int last_index)
{
    for (int j = 0; j < last_index; j++)
        if (array[j] == i)
            return 1;
    return SUCCESS;
}

void init_empty_array_bfs(file_info_t *info, int *array)
{
    for (int i = 0; i <= info->nb_rooms; i++)
        array[i] = -1;
    array[0] = get_equivalent(info, info->start_name);
}

int inside_loop_compare_array(int *reference, int *test_array, int g_cost_test,
int i)
{
    for (int j = 1; j < g_cost_test; j++)
        if (reference[i] == test_array[j])
            return 1;
    return SUCCESS;
}

int compare_array(int *reference, int *test_array, int g_cost_reference,
int g_cost_test)
{
    if (reference == NULL || test_array == NULL)
        return 1;
    for (int i = 1; i < (g_cost_reference - 1); i++)
        if (inside_loop_compare_array(reference, test_array, g_cost_test,
        i) == 1)
            return 1;
    return SUCCESS;
}
