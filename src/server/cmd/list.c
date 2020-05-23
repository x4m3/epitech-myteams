/*
** EPITECH PROJECT, 2020
** epitech-myteams
** File description:
** list
*/

#include "server.h"

void cmd_list(net_user_t *user, char **args)
{
    (void) args;
    client_response(user->socket_fd, "list");
}
