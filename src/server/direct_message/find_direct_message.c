/*
** EPITECH PROJECT, 2019
** name of the project
** File description:
** foo
*/

#include "server.h"

direct_message_t *find_direct_messsage(
    user_info_t *user, my_teams_t *my_teams, char *user_uuid)
{
    TAILQ_FOREACH(my_teams->list_of_direct_message,
        &my_teams->direct_message_head, next_direct_message)
    {
        if (strcmp(my_teams->list_of_direct_message->uuid1, user->user_uuid)
                == 0
            && strcmp(my_teams->list_of_direct_message->uuid2, user_uuid) == 0)
            return my_teams->list_of_direct_message;
        if (strcmp(my_teams->list_of_direct_message->uuid2, user->user_uuid)
                == 0
            && strcmp(my_teams->list_of_direct_message->uuid1, user_uuid) == 0)
            return my_teams->list_of_direct_message;
    }
    return NULL;
}
