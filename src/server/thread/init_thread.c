/*
** EPITECH PROJECT, 2019
** name of the project
** File description:
** foo
*/

#include "server.h"

thread_t *init_thread(channel_t *channel)
{
    TAILQ_INIT(&channel->thread_head);
    return channel->list_of_thread;
}
