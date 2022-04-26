/*
** EPITECH PROJECT, 2021
** LE-MIN
** File description:
** check_room_norm.c
*/

#include "lib.h"
#include "lemin.h"

int same_room_coords(room_t **room_l, int row, int col)
{
    for (room_t *temp = *room_l; temp != NULL; temp = temp->next)
        if (temp->row == row && temp->col == col)
            return 1;
    return SUCCESS;
}

int same_room_name(room_t **room_l, char *name)
{
    for (room_t *temp = *room_l; temp; temp = temp->next)
        if (!my_strcmp(temp->room_name, name))
            return 1;
    return SUCCESS;
}

int check_room_norm(room_t **room_l, char *str)
{
    int row = 0, col = 0, len = 2;
    char **map = my_strtok(str, ' ');
    if ((map == NULL) || (get_nb_row(map) < 3) ||
    (row = my_atoi(map[1])) == -1 || (col = my_atoi(map[2])) == -1) {
        free_map(map);
        return 1;
    }
    if (same_room_coords(room_l, row, col) == 1 ||
    same_room_name(room_l, map[0]) == 1) {
        free_map(map);
        return 1;
    }
    for (int i = 0; map[i]; i++)
        len += my_strlen(map[i]);
    room_t *new = create_room_node(str, map[0], row, col);
    new->room_line_len = len;
    add_room(room_l, new);
    free_map(map);
    return SUCCESS;
}
