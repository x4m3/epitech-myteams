/*
** EPITECH PROJECT, 2019
** name of the project
** File description:
** foo
*/

#include "server.h"

void list_reply_thread(thread_t *thread)
{
    TAILQ_FOREACH(thread->list_of_message, &thread->message_head, next_message)
    {
        printf("%ld %s : %s", thread->list_of_message->creation_date,
            thread->list_of_message->author,
            thread->list_of_message->body_message);
    }
}
