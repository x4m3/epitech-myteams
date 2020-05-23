/*
** EPITECH PROJECT, 2020
** epitech-myteams
** File description:
** create
*/

#include "server.h"

void cmd_create(net_user_t *user, char **args)
{
    (void) args;
    client_response(user->socket_fd, "create");
}
