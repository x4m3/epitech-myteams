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
        TAILQ_REMOVE(&team->my_teams_uuid_head,
            team->my_teams_uuid_head.tqh_first, next_user_uuid);
        free(team->uuid_subcribed);
    }
}

void delete_myteams_uuid_in_user(user_info_t *user)
{
    while (user->my_teams_uuid_head.tqh_first != NULL) {
        user->uuid_subcribed = TAILQ_FIRST(&user->my_teams_uuid_head);
        TAILQ_REMOVE(&user->my_teams_uuid_head,
            user->my_teams_uuid_head.tqh_first, next_user_uuid);
        free(user->uuid_subcribed);
    }
}
