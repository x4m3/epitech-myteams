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
** @brief check number of quotes in a string
**
** @param str
** @return true
** @return false
**
** to be considered valid, a parameter needs to be surrounded with quotes
** this function checks if there is the correct amount of quotes
*/
static bool check_quotes(const char *str)
{
    size_t nb = 0;

    for (size_t i = 0; str[i] != 0; i++) {
        if (str[i] == '"')
            nb++;
    }
    if (nb == 0)
        return false;
    return (nb % 2 == 0) ? true : false;
}

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
    for (size_t i = 1; args[i] != NULL; i++) {
        if (check_quotes(args[i]) == false) {
            client_response(socket_fd, "bad nb of quotes");
            return false;
        }
    }
    return true;
}
