/*
** EPITECH PROJECT, 2020
** epitech-myteams
** File description:
** messages
*/

#include "server.h"

void cmd_messages(net_user_t *user, char **args)
{
    my_teams_t *global_teams = get_global_teams(NULL);
    char *uuid1 = NULL;

    if (check_input_args(1, args, user->socket_fd) == false)
        return;
    uuid1 = args[1];
    global_teams->list_of_direct_message =
        find_direct_messsage(user->user, global_teams, uuid1);
    list_private_message(
        global_teams->list_of_direct_message, user->socket_fd);
}
