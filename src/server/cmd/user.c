/*
** EPITECH PROJECT, 2020
** epitech-myteams
** File description:
** user
*/

#include "server.h"

void cmd_user(net_user_t *user, char **args)
{
    (void) args;
    client_response(user->socket_fd, "user");
}
