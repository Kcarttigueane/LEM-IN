/*
** EPITECH PROJECT, 2021
** LE-MIN
** File description:
** main.c
*/

#include "lib.h"
#include "lemin.h"

int error_check(file_info_t *infos)
{
    if (infos->start_name == NULL || infos->end_name == NULL)
        return ERROR;
    return SUCCESS;
}

void fill_infos_data_struct(file_info_t *infos, room_t **room_list,
tunnel_t **tunnel_list)
{
    infos->nb_rooms = get_room_list_size(room_list);
    infos->nb_tunnels = get_tunnel_list_size(tunnel_list);
    infos->adjency_matrix = malloc_world_int_array(infos->nb_rooms,
    infos->nb_rooms);
}

#define ERROR_HANDLING\
    if (argc != 1 || argv[0] == NULL)\
        return ERROR;\

#define BFS\
    if (bfs(&front, &rear, infos, &path_list) == 84)\
        return ERROR;\

int main(int argc, char **argv)
{
    ERROR_HANDLING;
    file_info_t *infos = malloc(sizeof(file_info_t));
    memset_file_info(infos);
    room_t *room_l = NULL;
    tunnel_t *tunnel_l = NULL;
    path_t *path_list = NULL;
    if (read_file(infos, &room_l, &tunnel_l) == 84)
        return ERROR;
    if (solution(&room_l, &tunnel_l, infos) == 84 || error_check(infos) == 84)
        return SUCCESS;
    fill_infos_data_struct(infos, &room_l, &tunnel_l);
    hash_map_alternatives(infos, &room_l);
    node_t *front = NULL;
    node_t *rear = NULL;
    make_graph(infos, &tunnel_l);
    get_max_path_value(infos, infos->end_name, infos->start_name);
    BFS;
    path_finding(infos, &path_list);
    free_stuff(infos, &path_list, &room_l, &tunnel_l);
    return SUCCESS;
}
