/*
** EPITECH PROJECT, 2019
** name of the project
** File description:
** foo
*/

#include "server.h"

direct_message_t *init_direct_message(my_teams_t *my_teams)
{
    if ((my_teams->list_of_direct_message = malloc(sizeof(direct_message_t)))
        == NULL)
        return NULL;
    memset(my_teams->list_of_direct_message, 0, sizeof(direct_message_t));
    TAILQ_INIT(&my_teams->direct_message_head);
    init_conversation(my_teams->list_of_direct_message);
    return my_teams->list_of_direct_message;
}
