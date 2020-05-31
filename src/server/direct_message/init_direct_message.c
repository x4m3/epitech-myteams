/*
** EPITECH PROJECT, 2019
** name of the project
** File description:
** foo
*/

#include "server.h"

direct_message_t *init_direct_message(my_teams_t *my_teams)
{
    TAILQ_INIT(&my_teams->direct_message_head);
    return my_teams->list_of_direct_message;
}
