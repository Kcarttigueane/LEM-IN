/*
** EPITECH PROJECT, 2021
** LE-MIN
** File description:
** graph.c
*/

#include "lib.h"
#include "lemin.h"

int get_equivalent(file_info_t *infos, char *str)
{
    for (int i = 0; i < infos->nb_rooms; i++)
        if (!my_strcmp(infos->name_array[i].name, str))
            return infos->name_array[i].index;
    return (-1);
}

void make_graph(file_info_t *infos, tunnel_t **tunnel_list)
{
    int row = 0, col = 0;

    for (tunnel_t *temp = *tunnel_list; temp; temp = temp->next) {
        row = get_equivalent(infos, temp->first_name);
        col = get_equivalent(infos, temp->secund_name);
        infos->adjency_matrix[row][col] = 1;
        infos->adjency_matrix[col][row] = 1;
    }
}

void hash_map_alternatives(file_info_t *infos, room_t **room_list)
{
    infos->name_array = malloc(sizeof(node_name_t) * (infos->nb_rooms));
    memset_file_info_array(infos);

    int i = 0;
    for (room_t *temp = *room_list; temp; temp = temp->next) {
        infos->name_array[i].name = temp->room_name;
        infos->name_array[i].index = i;
        i++;
    }
}
