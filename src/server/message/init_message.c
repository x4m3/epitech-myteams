/*
** EPITECH PROJECT, 2019
** name of the project
** File description:
** foo
*/

#include <stdlib.h>
#include <string.h>
#include "server.h"

message_t *init_message(thread_t *thread)
{
    TAILQ_INIT(&thread->message_head);
    return thread->list_of_message;
}

message_t *init_conversation(direct_message_t *direct_message)
{
    TAILQ_INIT(&direct_message->message_head);
    return direct_message->list_of_message;
}
