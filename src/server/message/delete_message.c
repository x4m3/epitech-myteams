/*
** EPITECH PROJECT, 2019
** name of the project
** File description:
** foo
*/

#include "server.h"

void delete_message(message_t *message)
{
    while (message_.tqh_first != NULL) {
        message_list = TAILQ_FIRST(&message_head);
        TAILQ_REMOVE(&message_head, message_head.tqh_first, next);
        free(message_list);
    }
}
