/*
** EPITECH PROJECT, 2019
** name of the project
** File description:
** foo
*/

#include <stdlib.h>
#include <string.h>
#include "server.h"

thread_t *init_thread(channel_t *channel)
{
    if ((channel->list_of_thread = malloc(sizeof(thread_t))) == NULL)
        return NULL;
    memset(channel->list_of_thread, 0, sizeof(thread_t));
    TAILQ_INIT(&channel->thread_head);
    init_message(channel->list_of_thread);
    return channel->list_of_thread;
}
