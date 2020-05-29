/*
** EPITECH PROJECT, 2019
** name of the project
** File description:
** foo
*/

#include "server.h"

void list_private_message(direct_message_t *direct_message)
{
    TAILQ_FOREACH(direct_message->list_of_message,
        &direct_message->message_head, next_message)
    {
        printf("%ld %s : %s\n", direct_message->list_of_message->creation_date,
            direct_message->list_of_message->author,
            direct_message->list_of_message->body_message);
    }
}
