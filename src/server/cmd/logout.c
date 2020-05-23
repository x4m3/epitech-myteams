/*
** EPITECH PROJECT, 2020
** epitech-myteams
** File description:
** logout
*/

#include "server.h"

void cmd_logout(net_user_t *user, char **args)
{
    (void) args;
    client_response(user->socket_fd, "logout");
}
