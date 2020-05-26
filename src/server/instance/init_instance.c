/*
** EPITECH PROJECT, 2019
** name of the project
** File description:
** foo
*/

#include <stdlib.h>
#include <string.h>
#include "server.h"

instance_t *init_instance(user_info_t *user)
{
    if ((user->list_of_instance = malloc(sizeof(instance_t))) == NULL)
        return NULL;
    memset(user->list_of_instance, 0, sizeof(instance_t));
    TAILQ_INIT(&user->instance_head);
    return user->list_of_instance;
}
