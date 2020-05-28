/*
** EPITECH PROJECT, 2019
** name of the project
** File description:
** foo
*/

#include "server.h"

void delete_thread(channel_t *channel)
{
    while (channel->thread_head.tqh_first != NULL) {
        channel->list_of_thread = TAILQ_FIRST(&channel->thread_head);
        TAILQ_REMOVE(&channel->thread_head, channel->thread_head.tqh_first,
            next_thread);
        delete_message(channel->list_of_thread, 't');
        free(channel->list_of_thread);
    }
    if (channel->list_of_thread != NULL) {
        delete_message(channel->list_of_thread, 't');
        free(channel->list_of_thread);
    }
}
