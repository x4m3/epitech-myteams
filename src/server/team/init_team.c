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
    if ((my_teams->list_of_team = malloc(sizeof(team_t))) == NULL)
        return NULL;
    memset(my_teams->list_of_team, 0, sizeof(team_t));
    TAILQ_INIT(&my_teams->team_head);
    return team;
}
