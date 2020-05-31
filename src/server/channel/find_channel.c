/*
** EPITECH PROJECT, 2019
** name of the project
** File description:
** foo
*/

#include "server.h"

channel_t *find_channel(team_t *team, char *uuid)
{
    TAILQ_FOREACH(team->list_of_channel, &team->channel_head, next_channel)
    {
        if (strcmp(team->list_of_channel->channel_uuid, uuid) == 0)
            return team->list_of_channel;
    }
    return NULL;
}
