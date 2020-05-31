/*
** EPITECH PROJECT, 2019
** name of the project
** File description:
** foo
*/

#include "server.h"

int get_number_params(char **args)
{
    int number_params = 0;

    for (size_t i = 0; args[i] != NULL; i++)
        number_params++;
    return number_params - 1;
}
