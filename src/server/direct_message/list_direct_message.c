/*
** EPITECH PROJECT, 2019
** name of the project
** File description:
** foo
*/

#include "server.h"

void list_direct_message(char author[UUID_STR_LEN], my_teams_t *my_teams)
{
    TAILQ_FOREACH(my_teams->list_of_direct_message,
        &my_teams->direct_message_head, next_direct_message)
    {
        if (strcmp(my_teams->list_of_direct_message->list_of_message->author,
                author)
            == 0)
            list_private_message(my_teams->list_of_direct_message);
    }
}
