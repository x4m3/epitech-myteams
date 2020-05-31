/*
** EPITECH PROJECT, 2019
** name of the project
** File description:
** foo
*/

#include "server.h"

thread_t *add_thread(char author[MAX_NAME_LENGTH],
    char title[MAX_DESCRIPTION_LENGTH], char message[MAX_BODY_LENGTH],
    channel_t *channel)
{
    uuid_t new_uuid_bin;
    time_t now = time(NULL);

    if ((channel->list_of_thread = malloc(sizeof(thread_t))) == NULL)
        return NULL;
    memset(channel->list_of_thread, 0, sizeof(thread_t));
    uuid_generate_random(new_uuid_bin);
    uuid_unparse(new_uuid_bin, channel->list_of_thread->thread_uuid);
    strcpy(channel->list_of_thread->title, title);
    strcpy(channel->list_of_thread->message, message);
    strcpy(channel->list_of_thread->author, author);
    channel->list_of_thread->creation_date = now;
    init_message(channel->list_of_thread);
    TAILQ_INSERT_HEAD(
        &channel->thread_head, channel->list_of_thread, next_thread);
    printf("add new channel: [%s] [%s]\n", channel->list_of_thread->title,
        channel->list_of_thread->message);
    return channel->list_of_thread;
}
