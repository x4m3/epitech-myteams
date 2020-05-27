/*
** EPITECH PROJECT, 2020
** epitech-myteams
** File description:
** login
*/

#include "server.h"

void cmd_login(net_user_t *user, char **args)
{
    if (check_input_args(1, args, user->socket_fd) == false)
        return;
    client_response(user->socket_fd, "login");
}
