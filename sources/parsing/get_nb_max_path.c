/*
** EPITECH PROJECT, 2021
** LE-MIN
** File description:
** get_nb_max_path.c
*/

#include "lib.h"
#include "lemin.h"

void get_max_path_value(file_info_t *infos, char *end_name, char *start_name)
{
    int end_name_index = get_equivalent(infos, end_name);
    int start_name_index = get_equivalent(infos, start_name);

    int j = 0, k = 0;
    for (int i = 0; i < infos->nb_rooms; i++) {
        if (infos->adjency_matrix[i][end_name_index] == 1)
            j++;
        if (infos->adjency_matrix[start_name_index][i] == 1)
            k++;
    }
    infos->max_path = (k > j) ? j : k;
}
