/*
** EPITECH PROJECT, 2019
** name of the project
** File description:
** foo
*/

#include "server.h"

void list_users_subscribed(team_t *team, int socket_user)
{
    TAILQ_FOREACH(
        team->uuid_subcribed, &team->my_teams_uuid_head, next_user_uuid)
    {
        client_response(socket_user, team->uuid_subcribed->uuid);
    }
}
