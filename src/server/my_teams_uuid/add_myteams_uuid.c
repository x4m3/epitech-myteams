/*
** EPITECH PROJECT, 2019
** name of the project
** File description:
** foo
*/

#include "server.h"

myteams_uuid_t *add_team_uuid(team_t *team, char user_uuid[UUID_STR_LEN])
{
    if ((team->uuid_subcribed = malloc(sizeof(myteams_uuid_t))) == NULL)
        return NULL;
    memset(team->uuid_subcribed, 0, sizeof(myteams_uuid_t));
    strcpy(team->uuid_subcribed->uuid, user_uuid);
    TAILQ_INSERT_HEAD(
        &team->my_teams_uuid_head, team->uuid_subcribed, next_user_uuid);
    printf("add new user subcribed: [%s]\n", team->uuid_subcribed->uuid);
    return team->uuid_subcribed;
}

myteams_uuid_t *add_team_to_user(user_info_t *user, char user_uuid[UUID_STR_LEN])
{
    if ((user->uuid_subcribed = malloc(sizeof(myteams_uuid_t))) == NULL)
        return NULL;
    memset(user->uuid_subcribed, 0, sizeof(myteams_uuid_t));
    strcpy(user->uuid_subcribed->uuid, user_uuid);
    TAILQ_INSERT_HEAD(
        &user->my_teams_uuid_head, user->uuid_subcribed, next_user_uuid);
    printf("add new user subcribed: [%s]\n", user->uuid_subcribed->uuid);
    return user->uuid_subcribed;
}
