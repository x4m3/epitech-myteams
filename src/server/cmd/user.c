/*
** EPITECH PROJECT, 2020
** epitech-myteams
** File description:
** user
*/

#include "server.h"

void cmd_user(net_user_t *user, char **args)
{
    my_teams_t *global_teams = get_global_teams(NULL);
    char *user_uuid = args[1];
    char *param_to_send_cli = NULL;

    if (check_input_args(1, args, user->socket_fd) == false)
        return;
    TAILQ_FOREACH(
        global_teams->users, &global_teams->user_info_head, next_users)
    {
        if (strcmp(global_teams->users->user_uuid, user_uuid) == 0) {
            param_to_send_cli = concat_args_to_cli(
                global_teams->users->user_uuid, global_teams->users->username,
                (global_teams->users->online == true) ? "0" : "1", NULL);
            break;
        }
    }
    if (param_to_send_cli == NULL)
        return;
    else {
        client_response(user->socket_fd, param_to_send_cli);
        free(param_to_send_cli);
    }
}
