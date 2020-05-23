/*
** EPITECH PROJECT, 2020
** epitech-myteams
** File description:
** info
*/

#include "server.h"

void cmd_info(net_user_t *user, char **args)
{
    (void) args;
    client_response(user->socket_fd, "info");
}
