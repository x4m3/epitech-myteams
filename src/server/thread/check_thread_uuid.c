/*
** EPITECH PROJECT, 2019
** name of the project
** File description:
** foo
*/

#include "server.h"

bool check_thread_uuid(channel_t *channel, char uuid_to_check[UUID_STR_LEN])
{
    TAILQ_FOREACH(channel->list_of_thread, &channel->thread_head, next_thread)
    {
        if (strcmp(channel->list_of_thread->thread_uuid, uuid_to_check) == 0)
            return true;
    }
    return false;
}
