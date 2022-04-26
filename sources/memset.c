/*
** EPITECH PROJECT, 2021
** LE-MIN
** File description:
** memset.c
*/

#include "lib.h"
#include "lemin.h"

void memset_file_info(file_info_t *information)
{
    information->ant_nb = 0;
    information->start_name = NULL;
    information->start_line = NULL;
    information->end_name = NULL;
    information->end_line = NULL;
    information->nb_rooms = 0;
    information->nb_tunnels = 0;
    information->max_path = 0;
    information->adjency_matrix = NULL;
}

void memset_file_info_array(file_info_t *information)
{
    for (int i = 0; i < information->nb_rooms; i++) {
        information->name_array[i].index = 0;
        information->name_array[i].name = NULL;
    }
}
