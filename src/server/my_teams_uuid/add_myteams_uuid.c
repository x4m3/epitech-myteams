/*
** EPITECH PROJECT, 2019
** name of the project
** File description:
** foo
*/

#include "server.h"

myteams_uuid_t *add_team_uuid(team_t *team)
{
    uuid_t new_uuid_bin;

    if ((team->uuid_subcribed = malloc(sizeof(myteams_uuid_t))) == NULL)
        return NULL;
    uuid_generate_random(new_uuid_bin);
    uuid_unparse(new_uuid_bin, team->uuid_subcribed->uuid);
    TAILQ_INSERT_HEAD(
        &team->my_teams_uuid_head, team->uuid_subcribed, next_user_uuid);
    printf("add new user subcribed: [%s]\n", team->uuid_subcribed->uuid);
    return team->uuid_subcribed;
}
