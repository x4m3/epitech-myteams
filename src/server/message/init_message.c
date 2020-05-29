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
    if ((thread->list_of_message = malloc(sizeof(message_t))) == NULL)
        return NULL;
    memset(thread->list_of_message, 0, sizeof(message_t));
    TAILQ_INIT(&thread->message_head);
    return thread->list_of_message;
}

message_t *init_conversation(direct_message_t *direct_message)
{
    if ((direct_message->list_of_message = malloc(sizeof(message_t))) == NULL)
        return NULL;
    memset(direct_message->list_of_message, 0, sizeof(message_t));
    TAILQ_INIT(&direct_message->message_head);
    return direct_message->list_of_message;
}
