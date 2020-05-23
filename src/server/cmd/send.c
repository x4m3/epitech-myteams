/*
** EPITECH PROJECT, 2020
** epitech-myteams
** File description:
** send
*/

#include "server.h"

void cmd_send(net_user_t *user, char **args)
{
    (void) args;
    client_response(user->socket_fd, "send");
}
