/*
** EPITECH PROJECT, 2019
** name of the project
** File description:
** foo
*/

#include "server.h"

void delete_channel(team_t *team)
{
    while (team->channel_head.tqh_first != NULL) {
        team->list_of_channel = TAILQ_FIRST(&team->channel_head);
        TAILQ_REMOVE(&team->channel_head, team->channel_head.tqh_first, next);
        delete_thread(team->list_of_channel);
        free(team->list_of_channel);
    }
}
