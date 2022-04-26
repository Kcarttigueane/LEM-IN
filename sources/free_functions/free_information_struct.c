/*
** EPITECH PROJECT, 2021
** LE-MIN
** File description:
** free_information_struct.c
*/

#include "lib.h"
#include "lemin.h"

void free_information_struct(file_info_t *information)
{
    if (information == NULL)
        return;
    free_string(information->start_name);
    free_string(information->start_line);
    free_string(information->end_name);
    free_string(information->end_line);
    free_int_world_array(information->adjency_matrix, information->nb_rooms);
    free(information);
    information = NULL;
}

void free_stuff(file_info_t *information, path_t **path_list,
room_t **room_list, tunnel_t **tunnel_list)
{
    free_information_struct(information);
    free_path_list(path_list);
    free_room_list(room_list);
    free_tunnel_list(tunnel_list);
}
