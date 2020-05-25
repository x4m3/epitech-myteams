/*
** EPITECH PROJECT, 2019
** name of the project
** File description:
** foo
*/

#include <stdlib.h>
#include <string.h>
#include "server.h"

message_t *init_message(void)
{
    message_t *message;

    if ((message = malloc(sizeof(message_t))) == NULL)
        return NULL;
    memset(message, 0, sizeof(message_t));
    TAILQ_INIT(&message_head);
    return message;
}
