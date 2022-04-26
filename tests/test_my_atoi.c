/*
** EPITECH PROJECT, 2021
** LE-MIN
** File description:
** my_atoi.c
*/

#include "lib.h"
#include <criterion/criterion.h>

Test(my_atoi0, test_my_atoi0)
{
    cr_assert_eq(123, my_atoi("123"));
    cr_assert_eq(-1, my_atoi("-125"));
    cr_assert_eq(-1, my_atoi("2147483648"));
    cr_assert_eq(-1, my_atoi("-2147483648"));
    cr_assert_eq(0, my_atoi("0"));
    cr_assert_eq(3, my_atoi("3"));
}
