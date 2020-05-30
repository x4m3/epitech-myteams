/*
** EPITECH PROJECT, 2019
** name of the project
** File description:
** foo
*/

#include "server.h"

bool delete_one_instance(user_info_t *user, int socket_fd)
{
    TAILQ_FOREACH(user->list_of_instance, &user->instance_head, next_instance)
    {
        if (user->list_of_instance->socket_fd == socket_fd) {
            TAILQ_REMOVE(
                &user->instance_head, user->list_of_instance, next_instance);
            if (user->list_of_instance != NULL) {
                free(user->list_of_instance);
            }
            return true;
        }
    }

    return false;
}

void delete_all_instances(user_info_t *user)
{
    while (user->instance_head.tqh_first != NULL) {
        user->list_of_instance = TAILQ_FIRST(&user->instance_head);
        TAILQ_REMOVE(&user->instance_head, user->instance_head.tqh_first,
            next_instance);
        if (user->list_of_instance != NULL) {
            free(user->list_of_instance);
        }
    }
}
