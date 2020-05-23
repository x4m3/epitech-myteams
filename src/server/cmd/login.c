/*
** EPITECH PROJECT, 2020
** epitech-myteams
** File description:
** login
*/

#include "server.h"

void cmd_login(net_user_t *user, char **args)
{
    (void) args;
    client_response(user->socket_fd, "login");
}
