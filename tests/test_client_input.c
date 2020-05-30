/*
** EPITECH PROJECT, 2020
** epitech-myteams
** File description:
** test_client_input
*/

#include <stdio.h>
#include <criterion/criterion.h>
#include "server.h"

char **client_input_wrapper(char *cmd)
{
    FILE *input = fmemopen(cmd, strlen(cmd), "r");
    char **array = NULL;

    cr_assert_not_null(input);
    array = client_input(input);
    fclose(input);
    cr_assert_not_null(array);
    return array;
}

Test(client_input, cmd_no_args)
{
    char **array = client_input_wrapper("/logout");

    cr_assert_str_eq(array[0], "/logout");
    for (size_t i = 0; array[i]; i++)
        free(array[i]);
    free(array);
}

Test(client_input, cmd_one_args)
{
    char **array = client_input_wrapper("/create \"hello people\"");

    cr_assert_str_eq(array[0], "/create");
    cr_assert_str_eq(array[1], "hello people");
    for (size_t i = 0; array[i]; i++)
        free(array[i]);
    free(array);
}
