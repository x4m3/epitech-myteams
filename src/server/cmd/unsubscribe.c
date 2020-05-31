/*
** EPITECH PROJECT, 2019
** name of the project
** File description:
** foo
*/

#include "server.h"

void cmd_unsubscribe(net_user_t *user, char **args)
{
    my_teams_t *global_teams = get_global_teams(NULL);
    char *team_uuid = args[1];

    if (is_team_exist(global_teams, team_uuid) == NULL)
        return client_response(user->socket_fd, "this uuid_team isn't exist");
    remove_team_to_user(user->user, team_uuid);
    server_event_user_leave_a_team(team_uuid, user->user->user_uuid);
    client_response(user->socket_fd, "you left the team");
}
