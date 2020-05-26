/*
** EPITECH PROJECT, 2019
** name of the project
** File description:
** foo
*/

#include "server.h"

channel_t *init_channel(team_t *team)
{
    if ((team->list_of_channel = malloc(sizeof(channel_t))) == NULL)
        return NULL;
    memset(team->list_of_channel, 0, sizeof(channel_t));
    TAILQ_INIT(&team->channel_head);
    init_thread(team->list_of_channel);
    return team->list_of_channel;
}
