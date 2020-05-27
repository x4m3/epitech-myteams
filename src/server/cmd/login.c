/*
** EPITECH PROJECT, 2020
** epitech-myteams
** File description:
** login
*/

#include "server.h"

void cmd_login(net_user_t *user, char **args)
{
    if (check_nb_args(args) != 1)
        return client_response(user->socket_fd, "bad nb of args");
    client_response(user->socket_fd, "login");
}
