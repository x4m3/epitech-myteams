/*
** EPITECH PROJECT, 2020
** epitech-myteams
** File description:
** users
*/

#include "server.h"

void cmd_users(net_user_t *user, char **args)
{
    (void) args;
    client_response(user->socket_fd, "users");
}
