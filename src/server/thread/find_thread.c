/*
** EPITECH PROJECT, 2019
** name of the project
** File description:
** foo
*/

#include "server.h"

thread_t *find_thread(channel_t *channel, char *uuid)
{
    TAILQ_FOREACH(channel->list_of_thread, &channel->thread_head, next_thread)
    {
        if (strcmp(channel->list_of_thread->thread_uuid, uuid) == 0)
            return channel->list_of_thread;
    }
    return NULL;
}
