/*
** EPITECH PROJECT, 2019
** name of the project
** File description:
** foo
*/

#include "server.h"

void delete_myteams_uuid(team_t *team)
{
    while (team->my_teams_uuid_head.tqh_first != NULL) {
        team->uuid_subcribed = TAILQ_FIRST(&team->my_teams_uuid_head);
        TAILQ_REMOVE(&team->my_teams_uuid_head, team->my_teams_uuid_head.tqh_first,
            next_user_uuid);
        free(team->uuid_subcribed);
    }
    if (team->uuid_subcribed != NULL) {
        free(team->uuid_subcribed);
    }
}
