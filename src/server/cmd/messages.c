/*
** EPITECH PROJECT, 2020
** epitech-myteams
** File description:
** messages
*/

#include "server.h"

void cmd_messages(net_user_t *user, char **args)
{
    (void) args;
    client_response(user->socket_fd, "messages");
}
