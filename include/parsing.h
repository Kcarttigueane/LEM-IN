/*
** EPITECH PROJECT, 2021
** LE-MIN
** File description:
** parsing.h
*/

#ifndef PARSING_H_
    #define PARSING_H_

    #define NB_ANT information->ant_nb

    #define IS_EMPTY_LINE \
        if (line[0] == '\0') \
            break;\

    #define IS_COMMENT_LINE \
        if (line[0] == '#' && line[1] != '#')\
            continue;

    #define IS_WRONG_COMMAND \
        if (is_command(line) == -1) \
            break;\

    #define GET_NUMBER_ANT \
        if (nb_ant_count == 0) {\
            nb_ant_count++;\
            NB_ANT = my_atoi(line);\
            if (NB_ANT == (-1) || NB_ANT == 0)\
                break;\
            continue;\
        }

    #define ROOM_NORM_CONDITION \
        if (check_room_norm(room_l, line) != 0)\
            break;\


    #define CHECK_NEXT_LINE_START \
        if ((line_size = getline(&line, &s, stdin)) != -1) {\
            line[my_strlen(line) - 1] = '\0';\
            ROOM_NORM_CONDITION;\
            information->start_line = my_strdup(line);\
            information->start_name = my_strndup(line, \
            get_len_delimiter(line, ' '));\
            continue;\
        }\

    #define START_COMMAND \
        if (is_command(line) == 1) {\
            nb_start++;\
            CHECK_START_END;\
            CHECK_NEXT_LINE_START;\
        }

    #define CHECK_NEXT_LINE_END \
        if ((line_size = getline(&line, &s, stdin)) != -1) {\
            line[my_strlen(line) - 1] = '\0';\
            ROOM_NORM_CONDITION;\
            information->end_line = my_strdup(line);\
            information->end_name = my_strndup(line, \
            get_len_delimiter(line, ' '));\
            continue;\
        }\

    #define END_COMMAND \
        if (is_command(line) == 2) {\
            nb_end++;\
            CHECK_START_END;\
            CHECK_NEXT_LINE_END;\
        }

    #define CHECK_START_END\
        if (nb_start > 1 || nb_end > 1)\
            break;\

    #define INSIDE_CONDITION_ADD_RT \
        if (line[i] == ' ') {\
            nb_room_valid = check_room_norm(room_l, line);\
            break;\
        }\
        if (line[i] == '-') {\
            nb_tunnel_valid = check_tunnel_norm(room_l, tunnel_l, line);\
            break;\
        }\

    #define ADD_ROOM_TUNNELS\
        for (int i = 0; line[i]; i++) {\
            INSIDE_CONDITION_ADD_RT;\
        }

    #define CHECK_ROOM_TUNNEL_VALID\
        if (nb_room_valid != 0) {\
            break;\
        }\
        if (nb_tunnel_valid != 0) {\
            break;\
        }

// ? FUNCTION PROTOTYPES :

    // ! READ FILES :

int read_file(file_info_t *information, room_t **room_l, tunnel_t **tunnel_l);


    // ! ROOM PARSING :

int same_room_coords(room_t **room_l, int row, int col);
int same_room_name(room_t **room_l, char *name);
int check_room_norm(room_t **room_l, char *str);
int is_command(char *str);
int check_lines(file_info_t *infos, room_t **room_l, char *line_buf);


    // ! TUNNELS PARSING :

int check_tunnel_norm(room_t **room_l, tunnel_t **tunnel_l, char *str);
int check_name_exist(room_t **room_l, char *first_name, char *secund_name);


    // ! GET NB ANTS :

int get_nb_ants(char *str, file_info_t *information);


// ! PATH PARSING :

void get_max_path_value(file_info_t *infos, char *end_name, char *start_name);


#endif/* PARSING_H_ */
