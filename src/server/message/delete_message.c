/*
** EPITECH PROJECT, 2019
** name of the project
** File description:
** foo
*/

#include "server.h"

static void delete_msg_thread(thread_t *thread)
{
    while (thread->message_head.tqh_first != NULL) {
        thread->list_of_message = TAILQ_FIRST(&thread->message_head);
        TAILQ_REMOVE(&thread->message_head, thread->list_of_message,
            next_message);
        if (thread->list_of_message != NULL)
            free(thread->list_of_message);
    }
}

static void delete_msg_teams(direct_message_t *direct_message)
{
    while (direct_message->message_head.tqh_first != NULL) {
        direct_message->list_of_message =
            TAILQ_FIRST(&direct_message->message_head);
        TAILQ_REMOVE(&direct_message->message_head,
            direct_message->list_of_message, next_message);
        if (direct_message->list_of_message != NULL)
            free(direct_message->list_of_message);
    }
}

void delete_conversation(direct_message_t *direct_message)
{
    delete_msg_teams(direct_message);
}

void delete_reply(thread_t *thread)
{
    delete_msg_thread(thread);
}
