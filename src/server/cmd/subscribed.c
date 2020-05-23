/*
** EPITECH PROJECT, 2020
** epitech-myteams
** File description:
** subscribed
*/

#include "server.h"

void cmd_subscribed(net_user_t *user, char **args)
{
    (void) args;
    client_response(user->socket_fd, "subscribed");
}
