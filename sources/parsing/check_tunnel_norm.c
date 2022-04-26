/*
** EPITECH PROJECT, 2021
** LE-MIN
** File description:
** check_tunnel_norm.c
*/

#include "lib.h"
#include "lemin.h"

int check_name_exist(room_t **room_l, char *first_name, char *secund_name)
{
    int i = -1;
    for (room_t *temp = *room_l; temp; temp = temp->next)
        if (!my_strcmp(temp->room_name, first_name)) {
            i = 1;
            break;
        }
    for (room_t *temp = *room_l; temp; temp = temp->next)
        if (!my_strcmp(temp->room_name, secund_name)) {
            i = 2;
            break;
        }
    return i;
}

int check_tunnel_norm(room_t **room_l, tunnel_t **tunnel_l, char *str)
{
    int len = 1;
    char **map = my_strtok(str, '-');
    if ((map == NULL) || (get_nb_row(map) != 2))
        return 1;
    if (check_name_exist(room_l, map[0], map[1]) != 2)
        return 1;
    for (int i = 0; map[i]; i++)
        len += my_strlen(map[i]);
    tunnel_t *new = create_tunnel_node(str, map[0], map[1]);
    new->tunnel_line_len = len;
    add_tunnel_node(tunnel_l, new);
    free_map(map);
    return SUCCESS;
}
