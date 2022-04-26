/*
** EPITECH PROJECT, 2021
** LE-MIN
** File description:
** data_struct.h
*/

#ifndef DATA_STRUCT_H_
    #define DATA_STRUCT_H_

    // ! STORE FILE INFORMATIONS :

typedef struct node_name {
    int index;
    char *name;
} node_name_t;

    // ! STORE ROOMS AND TUNNELS :

typedef struct rooms_list {
    char *room_line;
    int room_line_len;
    char *room_name;
    int row;
    int col;
    struct rooms_list *next;
} room_t;

typedef struct tunnels_list {
    char *tunnel_line;
    int tunnel_line_len;
    char *first_name;
    char *secund_name;
    struct tunnels_list *next;
} tunnel_t;

    // ! STORE INFORMATION :
typedef struct file_info {
    int ant_nb;
    char *start_name;
    char *start_line;
    char *end_name;
    char *end_line;
    int nb_rooms;
    int nb_tunnels;
    int max_path;
    int **adjency_matrix;
    node_name_t *name_array;
}   file_info_t;

    // ! BFS STRUCT :

typedef struct node {
    int *path_array;
    struct node *next;
} node_t;

    // ! LINKED LIST OF PATH :

typedef struct path_list {
    int *path_array;
    int g_cost;
    int halt;
    int path_number;
    struct path_list *next;
} path_t;

typedef struct path_find {
    int ant_number;
    int path_number;
    int is_reach_destination;
    int halt;
    int node_index;
} pf_t;

#endif/*DATA_STRUCT_H_*/
