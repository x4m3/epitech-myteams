/*
** EPITECH PROJECT, 2019
** name of the project
** File description:
** foo
*/

#include "server.h"

instance_t *add_instance(user_info_t *user, int socket_id)
{
    instance_t *new_instance = malloc(sizeof(instance_t));

    if (new_instance == NULL)
        return NULL;
    memset(new_instance, 0, sizeof(instance_t));
    new_instance->socket_id = socket_id;
    TAILQ_INSERT_TAIL(&user->instance_head, new_instance, next_instance);
    printf("added new instance for socket [%d]\n", new_instance->socket_id);
    return new_instance;
}
