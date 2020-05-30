/*
** EPITECH PROJECT, 2019
** name of the project
** File description:
** foo
*/

#include "server.h"

team_t *find_team(my_teams_t *my_teams, char uuid[UUID_STR_LEN])
{
    TAILQ_FOREACH(my_teams->list_of_team, &my_teams->team_head, next_team)
    {
        if (strcmp(my_teams->list_of_team->team_uuid, uuid) == 0)
            return my_teams->list_of_team;
    }
    return NULL;
}
