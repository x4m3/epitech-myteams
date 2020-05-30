/*
** EPITECH PROJECT, 2020
** epitech-myteams
** File description:
** test_client_input
*/

#include <stdio.h>
#include <criterion/criterion.h>
#include "server.h"

Test(client_input, cmd_no_args)
{
    char *cmd = "/logout";
    FILE *input = fmemopen(cmd, strlen(cmd), "r");
    cr_assert_not_null(input);
    char **array = client_input(input);
    fclose(input);
    cr_assert_not_null(array);

    cr_assert_str_eq(array[0], "/logout");
}

Test(client_input, cmd_one_args)
{
    char *cmd = "/create \"hello people\"";
    FILE *input = fmemopen(cmd, strlen(cmd), "r");
    cr_assert_not_null(input);
    char **array = client_input(input);
    fclose(input);
    cr_assert_not_null(array);

    cr_assert_str_eq(array[0], "/create");
    cr_assert_str_eq(array[1], "hello people");
}
