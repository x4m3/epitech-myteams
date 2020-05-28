/*
** EPITECH PROJECT, 2020
** epitech-myteams
** File description:
** get_number_instance
*/

#include "server.h"

size_t get_number_instance(user_info_t *user)
{
    size_t count = 0;
    TAILQ_FOREACH(user->list_of_instance, &user->instance_head, next_instance)
    {
        count++;
    }
    return count;
}
