/*
** EPITECH PROJECT, 2021
** C_LANGUAGE_EXPLORATION
** File description:
** test_my_strcmp.c
*/

#include "lib.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test (my_strcmp0, simple_tests_equal_string)
{
    cr_assert_eq(my_strcmp("la", "la"), 0);
    cr_assert_eq(my_strcmp("", ""), 0);
    cr_assert_eq(my_strcmp(" ", " "), 0);
    cr_assert_eq(my_strcmp("\t", "\t"), 0);
    cr_assert_eq(my_strcmp("\n", "\n"), 0);
    cr_assert_eq(my_strcmp("../,;::!?+*/-1656czuct   \t  \n", "../,;::!?+*/-1656czuct   \t  \n"), 0);
    cr_assert_eq(my_strcmp("exit", "exit"), 0);
    cr_assert_eq(my_strcmp("la vie est belle", "la vie est belle"), 0);
    cr_assert_eq(my_strcmp("la vie est belle", "la vie est belle"), 0);
    cr_assert_eq(my_strcmp("la vie est belle", "la vie est belle"), 0);
    cr_assert_eq(my_strcmp("la cnbqk bkn nofsn ùvesn", "la cnbqk bkn nofsn ùvesn"), 0);
}

Test (my_strcmp2, error_handling_NULL_string)
{
    cr_assert_eq(my_strcmp(NULL, NULL), (-1));
}

Test (my_strcmp3, diferent_string)
{
    cr_assert_eq(my_strcmp("la", "l"), 97);
    cr_assert_eq(my_strcmp("", "cds"), -99);
    cr_assert_eq(my_strcmp(" ", ""), 32);
    cr_assert_eq(my_strcmp("\n", "\t"), 1);
    cr_assert_eq(my_strcmp("\t", "tab"), -107);
    cr_assert_eq(my_strcmp("../,;::!?+*/-1656czuct   \t  \n", "../,;::!?+*/-1656czu   \t  \n"), 67);
    cr_assert_eq(my_strcmp("exit", "e"), 120);
    cr_assert_eq(my_strcmp("la vie est belle", "la vie est "), 98);
}
