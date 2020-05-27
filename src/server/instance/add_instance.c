/*
** EPITECH PROJECT, 2019
** name of the project
** File description:
** foo
*/

#include "server.h"

instance_t *add_instance(user_info_t *user, int socket_id)
{
    user->list_of_instance->socket_id = socket_id;
    TAILQ_INSERT_HEAD(
        &user->instance_head, user->list_of_instance, next_instance);
    printf("added new instance for socket [%d]\n",
        user->list_of_instance->socket_id);
    return user->list_of_instance;
}
