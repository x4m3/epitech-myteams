/*
** EPITECH PROJECT, 2019
** name of the project
** File description:
** foo
*/

#include "server.h"

void list_user_subcribed(my_teams_t *myTeams)
{
    TAILQ_FOREACH(myTeams->list_of_team->uuid_subcribed,
        &myTeams->list_of_team->my_teams_uuid_head, next_user_uuid)
    {
        printf("%s", myTeams->list_of_team->uuid_subcribed->uuid);
    }
}
