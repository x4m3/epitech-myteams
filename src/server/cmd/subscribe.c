/*
** EPITECH PROJECT, 2020
** epitech-myteams
** File description:
** subscribe
*/

#include "server.h"

team_t *is_team_exist(my_teams_t *myTeams, char uuid_send[UUID_STR_LEN])
{
    TAILQ_FOREACH(myTeams->list_of_team, &myTeams->team_head, next_team)
    {
        if (strcmp(myTeams->list_of_team->team_uuid, uuid_send) == 0)
            return myTeams->list_of_team;
    }
    return NULL;
}

void cmd_subscribe(net_user_t *user, char **args)
{
    my_teams_t *global_teams = get_global_teams(NULL);
    char *param_no_quotes = NULL;

    param_no_quotes = remove_quotes(args[1]);
    if (is_team_exist(global_teams, param_no_quotes) != NULL) {
        global_teams->list_of_team =
            is_team_exist(global_teams, param_no_quotes);
        add_team_uuid(global_teams->list_of_team);
    } else
        client_response(user->socket_fd, "this uuid_team isn't exist");
}
