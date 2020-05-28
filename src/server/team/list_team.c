/*
** EPITECH PROJECT, 2019
** name of the project
** File description:
** foo
*/

#include "server.h"

void list_team(my_teams_t *myTeams)
{
    TAILQ_FOREACH(myTeams->list_of_team, &myTeams->team_head, next_team)
    {
        printf("%s %s : %s\n", myTeams->list_of_team->name,
            myTeams->list_of_team->team_uuid,
            myTeams->list_of_team->description);
    }
}
