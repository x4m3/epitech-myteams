/*
** EPITECH PROJECT, 2019
** name of the project
** File description:
** foo
*/

#include "server.h"

void delete_team(team_t *team)
{
    while (team_head.tqh_first != NULL) {
        team = TAILQ_FIRST(&head);
        TAILQ_REMOVE(&head, head.tqh_first, next);
        free(team->username);
        delete_channel(team->list_of_channel);
        delete_message(team->list_of_message);
        free(team);
    }
}
