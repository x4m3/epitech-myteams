/*
** EPITECH PROJECT, 2020
** epitech-myteams
** File description:
** check_nb_args
*/

#include <stddef.h>

/**
** @brief check number of arguments in user input
**
** @param args array of command + arguments
** @return size_t number of arguments in array
*/
size_t check_nb_args(char **args)
{
    size_t nb = 0;

    while (args[nb] != NULL)
        nb++;
    return (nb - 1);
}
