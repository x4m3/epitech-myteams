/*
** EPITECH PROJECT, 2020
** epitech-myteams
** File description:
** subscribe
*/

#include "server.h"

void cmd_subscribe(net_user_t *user, char **args)
{
    (void) args;
    client_response(user->socket_fd, "subscribe");
}
