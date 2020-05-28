/*
** EPITECH PROJECT, 2019
** name of the project
** File description:
** foo
*/

#include "server.h"

void list_team(my_teams_t *myTeams, int socket_user)
{
    TAILQ_FOREACH(myTeams->list_of_team, &myTeams->team_head, next_team)
    {
        client_response(socket_user, myTeams->list_of_team->name);
        client_response(socket_user, myTeams->list_of_team->team_uuid);
        client_response(socket_user, myTeams->list_of_team->description);
    }
}
