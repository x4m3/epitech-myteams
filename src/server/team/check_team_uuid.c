/*
** EPITECH PROJECT, 2019
** name of the project
** File description:
** foo
*/

#include "server.h"

bool check_team_uuid(my_teams_t *my_teams, char uuid_to_check[UUID_STR_LEN])
{
    TAILQ_FOREACH(my_teams->list_of_team, &my_teams->team_head, next_team) {
        if (strcmp(my_teams->list_of_team->team_uuid, uuid_to_check) == 0)
            return true;
    }
    return false;
}
