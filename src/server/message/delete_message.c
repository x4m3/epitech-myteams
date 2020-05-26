/*
** EPITECH PROJECT, 2019
** name of the project
** File description:
** foo
*/

#include "server.h"

void delete_message(thread_t *thread)
{
    while (thread->message_head.tqh_first != NULL) {
        thread->list_of_message = TAILQ_FIRST(&thread->message_head);
        TAILQ_REMOVE(
            &thread->message_head, thread->message_head.tqh_first, next_message);
        free(thread->list_of_message);
    }
    free(thread);
}
