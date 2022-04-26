/*
** EPITECH PROJECT, 2021
** LE-MIN
** File description:
** add_tunnel_node.c
*/

#include "lib.h"
#include "lemin.h"

tunnel_t *create_tunnel_node(char *line, char *first, char *secund)
{
    tunnel_t *new_tunnel = malloc(sizeof(tunnel_t));

    if (new_tunnel == NULL)
        return (NULL);
    new_tunnel->tunnel_line = my_strdup(line);
    new_tunnel->first_name = my_strdup(first);
    new_tunnel->secund_name = my_strdup(secund);
    new_tunnel->next = NULL;
    return (new_tunnel);
}

void add_tunnel_node(tunnel_t **tunnel_list, tunnel_t *new)
{
    tunnel_t *temp = *tunnel_list;

    if (temp == NULL) {
        *tunnel_list = new;
        return;
    }
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = new;
}

int get_tunnel_list_size(tunnel_t **tunnel_list)
{
    int size = 0;
    if (*tunnel_list == NULL)
        return SUCCESS;
    for (tunnel_t *temp = *tunnel_list; temp; temp = temp->next)
        size++;
    return size;
}

int print_tunnel_list(tunnel_t **tunnel_list)
{
    if (*tunnel_list == NULL)
        return ERROR;
    for (tunnel_t *temp = *tunnel_list; temp; temp = temp->next) {
        write(1, temp->tunnel_line, temp->tunnel_line_len);
        write(1, "\n", 1);
    }
    return SUCCESS;
}

void free_tunnel_list(tunnel_t **tunnel_list)
{
    if (*tunnel_list == NULL)
        return;
    tunnel_t *current = *tunnel_list;
    while (*tunnel_list) {
        current = *tunnel_list;
        *tunnel_list = (*tunnel_list)->next;
        free_string(current->tunnel_line);
        free_string(current->first_name);
        free_string(current->secund_name);
        free(current);
    }
    *tunnel_list = NULL;
}
