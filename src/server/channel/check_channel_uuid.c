/*
** EPITECH PROJECT, 2019
** name of the project
** File description:
** foo
*/

#include "server.h"

bool check_channel_uuid(team_t *team, char uuid_to_check[UUID_STR_LEN])
{
    TAILQ_FOREACH(team->list_of_channel, &team->channel_head, next_channel) {
        if (strcmp(team->list_of_channel->channel_uuid, uuid_to_check) == 0)
            return true;
    }
    return false;
}
