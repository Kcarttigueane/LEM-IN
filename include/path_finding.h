/*
** EPITECH PROJECT, 2021
** B-CPE-200-LYN-2-1-lemin-tom.desalmand
** File description:
** path_finding.h
*/

#ifndef PATH_FINDING_H
    #define PATH_FINDING_H

    #include "lemin.h"
    #include "data_struct.h"

    // ! ALGO FUNCTIONS :

int get_equivalent(file_info_t *information, char *str);
void make_graph(file_info_t *infos, tunnel_t **tunnel_list);
void hash_map_alternatives(file_info_t *infos, room_t **room_list);


    // ! BFS :

int get_last_index(int *array);
int is_in_array(int *array, int i, int last_index);
int bfs(node_t **front, node_t **rear, file_info_t *information,
 path_t **p_list);
void init_empty_array_bfs(file_info_t *info, int *array);
int inside_loop_compare_array(int *reference, int *test_array,
int g_cost_test, int i);


    // ! PATHFINDING :

int get_optimal_path(path_t **path_list, pf_t *ant);
int compare_path_taken(int *array, int path_number, int array_len);
char *print_path_ant(int path_number, path_t **path_list, file_info_t *info,
int index);
void path_finding(file_info_t *infos, path_t **path_list);

int compare_array(int *reference, int *test_array, int g_cost_reference,
int g_cost_test);



#endif/* !PATH_FINDING_H */
