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

    if (user->user == NULL)
        return client_response(user->socket_fd, "not logged in");
    if (get_number_instance(user->user) == 1)
        user->user->online = false;
    delete_one_instance(user->user, user->socket_fd);
    server_event_user_logged_out(user->user->user_uuid);
    client_response(user->socket_fd, "you are now logged out");
}
