/*
** EPITECH PROJECT, 2020
** epitech-myteams
** File description:
** check_input_args
*/

#include <stdbool.h>
#include <stddef.h>
#include "server.h"

/**
** @brief check number of arguments in user input
**
** @param args array of command + arguments
** @return size_t number of arguments in array
*/
static size_t check_nb_args(char **args)
{
    size_t nb = 0;

    while (args[nb] != NULL)
        nb++;
    return (nb - 1);
}

/**
** @brief check if input is correct
**
** @param nb number of arguments required
** @param args array of arguments
** @param socket_fd user socket fd
** @return true okay
** @return false not okay
*/
bool check_input_args(const size_t nb, char **args, int socket_fd)
{
    if (check_nb_args(args) != nb) {
        client_response(socket_fd, "bad nb of args");
        return false;
    }
    return true;
}
