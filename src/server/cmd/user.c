/*
** EPITECH PROJECT, 2020
** epitech-myteams
** File description:
** user
*/

#include "server.h"

void cmd_user(net_user_t *user, char **args)
{
    bool found = false;
    my_teams_t *global_teams = get_global_teams(NULL);
    char *user_uuid = args[1];

    if (check_input_args(1, args, user->socket_fd) == false)
        return;
    TAILQ_FOREACH(
        global_teams->users, &global_teams->user_info_head, next_users)
    {
        if (strcmp(global_teams->users->username, user_uuid) == 0) {
            client_response(user->socket_fd, global_teams->users->username);
            client_response(user->socket_fd, global_teams->users->user_uuid);
            (global_teams->users->online == true)
                ? client_response(user->socket_fd, "online")
                : client_response(user->socket_fd, "not online");
            found = true;
            break;
        }
    }
    if (found == false)
        client_response(user->socket_fd, "user doesn't exist");
}
