/*
** EPITECH PROJECT, 2019
** name of the project
** File description:
** foo
*/

#include "server.h"

void delete_direct_message(my_teams_t *my_team)
{
    while (my_team->direct_message_head.tqh_first != NULL) {
        my_team->list_of_direct_message = TAILQ_FIRST(&my_team->direct_message_head);
        TAILQ_REMOVE(
            &my_team->direct_message_head, my_team->direct_message_head.tqh_first, next_direct_message);
        free(my_team->list_of_direct_message);
    }
}
