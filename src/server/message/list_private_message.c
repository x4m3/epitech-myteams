/*
** EPITECH PROJECT, 2019
** name of the project
** File description:
** foo
*/

#include "server.h"

void list_private_message(direct_message_t *direct_message, int socket_user)
{
    printf("%p\n", &direct_message->message_head);
    TAILQ_FOREACH(direct_message->list_of_message,
        &direct_message->message_head, next_message)
    {
        client_response(socket_user, direct_message->list_of_message->author);
        client_response(
            socket_user, direct_message->list_of_message->body_message);
    }
}
