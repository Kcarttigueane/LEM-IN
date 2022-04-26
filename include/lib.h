/*
** EPITECH PROJECT, 2021
** LE-MIN
** File description:
** lib.h
*/

#ifndef LIB_H_
    #define LIB_H_

    #include <stdlib.h>
    #include <stdio.h>
    #include <unistd.h>
    #include <limits.h>

    #define ERROR 84
    #define SUCCESS 0

    // ! DISPLAY FUNCTIONS :

void my_putchar(char c);
void my_put_nbr(int nb);
void print_array(int *array, char *color);
void print_map(char **map);
void print_int_world_array(int **a, int nb_row, int cols);


    // ! STRING FUNCTIONS :

int my_strlen(char *str);
int get_len_delimiter(char *str, char end_point);
char *my_strdup(char *str);
char *my_strndup(const char *str, int n);
char *my_strcpy(char *dest, char const *src);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strncpy(char *dest, char const *src, int n);
int my_str_is_num(char *str);
int my_atoi(char *str);


    // ! OTHER FUNCTIONS :

int **malloc_world_int_array(int nb_rows, int nb_cols);
int get_nb_row(char **map);


    // ! FREE FUNCTIONS :

void free_string(char *str);
void free_map(char **map);
void free_int_world_array(int **array, int row);
void free_array(int *array);


    // ! DEBUG FUNCTIONS :

void debug_world_array(char **world);


    // ! SPLIT STR :

int get_len_word(char *str, const char delimiter);
int get_number_of_row(char *str, const char delimiter);
char *remove_tab(char *str);
char **my_strtok(char *str, const char delimiter);

#endif /* !LIB_H_ */
