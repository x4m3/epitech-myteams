/*
** EPITECH PROJECT, 2020
** epitech-myteams
** File description:
** use
*/

#include "server.h"

void cmd_use(net_user_t *user, char **args)
{
    (void) args;
    client_response(user->socket_fd, "use");
}
