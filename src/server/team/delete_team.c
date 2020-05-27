/*
** EPITECH PROJECT, 2019
** name of the project
** File description:
** foo
*/

#include "server.h"

void delete_team(my_teams_t *my_team)
{
    while (my_team->team_head.tqh_first != NULL) {
        my_team->list_of_team = TAILQ_FIRST(&my_team->team_head);
        TAILQ_REMOVE(
            &my_team->team_head, my_team->team_head.tqh_first, next_team);
        delete_channel(my_team->list_of_team);
        free(my_team->list_of_team);
    }
    if (my_team->list_of_team != NULL) {
        delete_channel(my_team->list_of_team);
        delete_myteams_uuid(my_team->list_of_team);
        free(my_team->list_of_team);
    }
}
