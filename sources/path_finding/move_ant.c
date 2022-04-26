/*
** EPITECH PROJECT, 2021
** B-CPE-200-LYN-2-1-lemin-tom.desalmand
** File description:
** move_ant.c
*/

#include "lib.h"
#include "lemin.h"

int get_optimal_path(path_t **path_list, pf_t *ant)
{
    path_t *temp = *path_list;
    int min = temp->g_cost;
    int optimal_path = 0;

    for (; temp; temp = temp->next)
        if (min > temp->g_cost) {
            min = temp->g_cost;
            optimal_path = temp->path_number;
        }
    for (path_t *temp2 = *path_list; temp2; temp2 = temp2->next)
        if (optimal_path == temp2->path_number) {
            temp2->g_cost++;
            ant->halt = temp2->halt;
            temp2->halt++;
        }
    return optimal_path;
}

int compare_path_taken(int *array, int path_number, int array_len)
{
    for (int i = 0; i < array_len; i++)
        if (array[i] == path_number)
            return 1;
    return SUCCESS;
}

char *print_path_ant(int path_number, path_t **path_list, file_info_t *info,
int index)
{
    for (path_t *tmp = *path_list; tmp; tmp = tmp->next)
        if (tmp->path_number == path_number)
                return info->name_array[tmp->path_array[index]].name;
    return NULL;
}

void memeset_pf_array(file_info_t *infos, pf_t *pf, path_t **path_list,
int *array)
{
    for (int i = 0; i < infos->ant_nb; i++) {
        pf[i].ant_number = i;
        pf[i].path_number = get_optimal_path(path_list, &pf[i]);
        pf[i].is_reach_destination = 0;
        pf[i].node_index = 1;
    }
    for (int j = 0; j < infos->nb_rooms; j++)
        array[j] = (-1);
}

#define MOVE_ANT\
    for (int i = 0; i < total_ant; i++) {\
        if (pf[i].is_reach_destination == 0)\
            stop = 0;\
        if (pf[i].halt <= 0 && !pf[i].is_reach_destination) {\
            node_name = print_path_ant(pf[i].path_number, \
            path_list, infos, pf[i].node_index);\
            if (count)\
                write(1, " ", 1);\
            write(1, "P", 1);\
            my_put_nbr(i + 1);\
            write(1, "-", 1);\
            write(1, node_name, my_strlen(node_name));\
            if (!my_strcmp(node_name, end_name))\
                pf[i].is_reach_destination = 1;\
            pf[i].node_index++;\
            count++;\
        }\
        pf[i].halt--;\
    }\

void path_finding(file_info_t *infos, path_t **path_list)
{
    pf_t *pf = malloc(sizeof(pf_t) * (infos->ant_nb));
    int *array_path = malloc(sizeof(int) * (infos->nb_rooms));
    memeset_pf_array(infos, pf, path_list, array_path);
    int total_ant = infos->ant_nb;

    int stop = 0;
    char *end_name = infos->end_name;
    char *node_name;
    int count = 0;
    while (stop == 0) {
        stop = 1;
        count = 0;
        MOVE_ANT;
        if (!stop)
            write(1, "\n", 1);
    }
}
