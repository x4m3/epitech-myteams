/*
** EPITECH PROJECT, 2019
** name of the project
** File description:
** foo
*/

#include "server.h"

instance_t *find_instance(user_info_t *user, int socket)
{
    TAILQ_FOREACH(user->list_of_instance, &user->instance_head, next_instance)
    {
        if (user->list_of_instance->socket_fd == socket)
            return user->list_of_instance;
    }
    return NULL;
}
