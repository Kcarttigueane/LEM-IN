/*
** EPITECH PROJECT, 2021
** LM
** File description:
** display_solution.c
*/

#include "lib.h"
#include "lemin.h"

int solution(room_t **room_list, tunnel_t **tunnel_list,
file_info_t *information)
{
    write(1, "#number_of_ants\n", 16);
    if (NB_ANT == -1 || NB_ANT == 0)
        return ERROR;
    my_put_nbr(NB_ANT);
    write(1, "\n", 1);
    write(1, "#rooms\n", 7);
    if (print_room_list(room_list, information) == 84)
        return ERROR;
    write(1, "#tunnels\n", 9);
    if (print_tunnel_list(tunnel_list) == 84)
        return ERROR;
    write(1, "#moves\n", 7);
    return SUCCESS;
}
