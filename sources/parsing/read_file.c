/*
** EPITECH PROJECT, 2021
** LE-MIN
** File description:
** read_file.c
*/

#include "lib.h"
#include "lemin.h"

int is_command(char *str)
{
    if (str[0] == '#' && str[1] == '#') {
        if (!my_strcmp(str, "##start"))
            return 1;
        if (!my_strcmp(str, "##end"))
            return 2;
        return -1;
    }
    return SUCCESS;
}

int read_file(file_info_t *information, room_t **room_l, tunnel_t **tunnel_l)
{
    char *line = NULL;
    size_t s = 0;
    ssize_t line_size = 0;
    int nb_ant_count = 0, nb_room_valid = 0, nb_tunnel_valid = 0, nb_start = 0,
    nb_end = 0, iteration = 0;
    while ((line_size = getline(&line, &s, stdin)) != -1) {
        iteration++;
        line[my_strlen(line) - 1] = '\0';
        IS_EMPTY_LINE;
        IS_COMMENT_LINE;
        IS_WRONG_COMMAND;
        GET_NUMBER_ANT;
        START_COMMAND;
        END_COMMAND;
        ADD_ROOM_TUNNELS;
        CHECK_ROOM_TUNNEL_VALID;
    }
    free(line);
    line = NULL;
    return (iteration == 0) ? 84 : 0;
}
