/*
** EPITECH PROJECT, 2021
** LE-MIN
** File description:
** bfs.c
*/

#include "lib.h"
#include "lemin.h"

#define ENQUEUE_ARRAY\
    for (int i = 0; i < information->nb_rooms; i++)\
        if ((is_in_array(array, i, last_index) == 0) &&\
        (information->adjency_matrix[array[last_index]][i] == 1)) {\
                array[last_index + 1] = i;\
                enqueue(front, rear, array, information->nb_rooms);\
        }\

#define ADD_PATH_TO_LIST \
    if (*p_list == NULL) {\
        add_path_node(p_list, array, count_path);\
        count_path++;\
        continue;\
    }\
    if (compare_array((*p_list)->path_array, array, (*p_list)->g_cost, \
    last_index) == 1)\
        continue;\
    add_path_node(p_list, array, count_path);\
    count_path++;\
    if (count_path == information->max_path)\
        break;\
    continue;\

int bfs(node_t **front, node_t **rear, file_info_t *information,
path_t **p_list)
{
    int *array = malloc(sizeof(int) * (information->nb_rooms + 1));
    int last_index = 0, count_path = 0;
    int end_node = get_equivalent(information, information->end_name);

    init_empty_array_bfs(information, array);
    enqueue(front, rear, array, information->nb_rooms);
    while (*front != NULL && *rear != NULL) {
        if ((array = dequeue(front, rear)) == NULL)
            break;
        last_index = get_last_index(array);
        if (array[last_index] == end_node) {
            ADD_PATH_TO_LIST;
        }
        ENQUEUE_ARRAY;
    }
    return (*p_list == NULL) ? 84 : 0;
}
