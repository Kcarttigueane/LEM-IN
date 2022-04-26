/*
** EPITECH PROJECT, 2021
** LE-MIN
** File description:
** add_room.c
*/

#include "lib.h"
#include "lemin.h"

room_t *create_room_node(char *room_line, char *name, int row, int col)
{
    room_t *new_room = malloc(sizeof(room_t));

    if (new_room == NULL)
        return (NULL);
    new_room->room_line = my_strdup(room_line);
    new_room->room_name = my_strdup(name);
    new_room->row = row;
    new_room->col = col;
    new_room->next = NULL;
    return (new_room);
}

void add_room(room_t **room_l, room_t *new_room)
{
    room_t *temp = *room_l;

    if (temp == NULL) {
        *room_l = new_room;
        return;
    }
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = new_room;
}

int get_room_list_size(room_t **romm_list)
{
    int size = 0;
    if (*romm_list == NULL)
        return SUCCESS;
    for (room_t *temp = *romm_list; temp; temp = temp->next)
        size++;
    return size;
}

int print_room_list(room_t **room_list, file_info_t *i)
{
    if (*room_list == NULL)
        return ERROR;
    for (room_t *temp = *room_list; temp; temp = temp->next) {
        if (i->start_line && !my_strcmp(temp->room_line, i->start_line)) {
            write(1, "##start\n", 8);
            write(1, i->start_line, my_strlen(i->start_line));
            write(1, "\n", 1);
            continue;
        }
        if (i->end_line != NULL && !my_strcmp(temp->room_line,
        i->end_line)) {
            write(1, "##end\n", 6);
            write(1, i->end_line, my_strlen(i->end_line));
            write(1, "\n", 1);
            continue;
        }
        write(1, temp->room_line, temp->room_line_len);
        write(1, "\n", 1);
    }
    return SUCCESS;
}

void free_room_list(room_t **romm_list)
{
    if (*romm_list == NULL)
        return;
    room_t *current = *romm_list;
    while (*romm_list) {
        current = *romm_list;
        *romm_list = (*romm_list)->next;
        free_string(current->room_line);
        free_string(current->room_name);
        free(current);
    }
    *romm_list = NULL;
}
