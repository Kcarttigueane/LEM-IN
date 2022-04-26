/*
** EPITECH PROJECT, 2021
** LE-MIN
** File description:
** lemin.h
*/

#ifndef LEMIN_H_
    #define LEMIN_H_

    #include <stdlib.h>
    #include <stdio.h>
    #include <unistd.h>
    #include <string.h>

    #include "bonus.h"
    #include "path_finding.h"
    #include "data_struct.h"
    #include "parsing.h"

    // ! DEFINE :

    #define TRUE 0
    #define FALSE 1

    #define ERROR 84
    #define SUCCESS 0

    #define NB_NODE information->nb_node

    // ! MEMSET FUNCTIONS :

void memset_file_info(file_info_t *information);
void memset_file_info_array(file_info_t *information);


    // ! LINKED LIST FUNCTIONS (use to store file content):

void free_room_list(room_t **romm_list);
void free_tunnel_list(tunnel_t **tunnel_list);

    // ? LL => ROOM :

room_t *create_room_node(char *room_line, char *name, int row, int col);
void add_room(room_t **room_l, room_t *new_room);
int print_room_list(room_t **room_list, file_info_t *infos);
int get_room_list_size(room_t **romm_list);

    // ? LL TUNNELS :

tunnel_t *create_tunnel_node(char *line, char *first, char *secund);
void add_tunnel_node(tunnel_t **tunnel_list, tunnel_t *new);
int print_tunnel_list(tunnel_t **tunnel_list);
int get_tunnel_list_size(tunnel_t **tunnel_list);

    // ? LL PATH_LIST :

path_t *create_path_node(int *array_path, int path_number);
void add_path_node(path_t **p_list, int *path_array, int path_number);
void print_path_list(path_t **path_list);
int get_len_sum_array(path_t **path_list);
void free_path_list(path_t **path_list);


    // ! QUEUE FUNCTIONS :

void enqueue(node_t **front, node_t **rear, int *array, int size);
int *dequeue(node_t **front, node_t **rear);
void print_queue(node_t **front, node_t **rear);


    // ! DEBUG FUNCTIONS :

void debug_info_struct_file(file_info_t *f);

// ! DISPLAY SOLUTION :

int solution(room_t **room_list, tunnel_t **tunnel_list,
file_info_t *information);
void display_solution_part_two(room_t **room_list, tunnel_t **tunnel_list,
file_info_t *information);

void free_information_struct(file_info_t *information);
void free_stuff(file_info_t *information, path_t **path_list,
room_t **room_list, tunnel_t **tunnel_list);

#endif/* !LEMIN_H_ */
