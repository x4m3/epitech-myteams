/*
** EPITECH PROJECT, 2019
** name of the project
** File description:
** foo
*/

#include <stdlib.h>
#include <string.h>
#include "server.h"

team_t *init_team(my_teams_t *my_teams)
{
    TAILQ_INIT(&my_teams->list_of_team->channel_head);
    TAILQ_INIT(&my_teams->list_of_team->my_teams_uuid_head);
    return my_teams->list_of_team;
}
