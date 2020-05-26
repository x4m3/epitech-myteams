/*
** EPITECH PROJECT, 2019
** name of the project
** File description:
** foo
*/

#include "server.h"

void delete_instance(user_info_t *user)
{
    while (user->instance_head.tqh_first != NULL) {
        user->list_of_instance = TAILQ_FIRST(&user->instance_head);
        TAILQ_REMOVE(&user->instance_head, user->instance_head.tqh_first,
            next_instance);
        free(user->list_of_instance);
    }
}
