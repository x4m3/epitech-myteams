/*
** EPITECH PROJECT, 2019
** name of the project
** File description:
** foo
*/

#include <stdlib.h>
#include <string.h>
#include "server.h"

team_t *init_team(void)
{
    team_t *team;

    TAILQ_HEAD(, team_t) team_head;
    if ((team = malloc(sizeof(team_t))) == NULL)
        return NULL;
    memset(team, 0, sizeof(team_t));
    TAILQ_INIT(&team_head);
    return team;

}
