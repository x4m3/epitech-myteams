/*
** EPITECH PROJECT, 2019
** name of the project
** File description:
** foo
*/

#include <string.h>
#include <stdlib.h>
#include "server.h"

team_t *init_team(void)
{
    team_t *team;

    if ((team = malloc(sizeof(team_t))) == NULL)
        return NULL;
    memset(team, 0, sizeof(team_t));
    return team;
}
