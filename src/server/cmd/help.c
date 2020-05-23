/*
** EPITECH PROJECT, 2020
** epitech-myteams
** File description:
** help
*/

#include "server.h"

void cmd_help(net_user_t *user, char **args)
{
    (void) args;
    client_response(user->socket_fd, "help");
}
