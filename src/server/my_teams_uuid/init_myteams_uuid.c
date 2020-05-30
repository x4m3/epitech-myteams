/*
** EPITECH PROJECT, 2019
** name of the project
** File description:
** foo
*/

#include <stdlib.h>
#include <string.h>
#include "server.h"

myteams_uuid_t *init_myteams_uuid(team_t *team)
{
    TAILQ_INIT(&team->my_teams_uuid_head);
    return team->uuid_subcribed;
}
