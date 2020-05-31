/*
** EPITECH PROJECT, 2019
** name of the project
** File description:
** foo
*/

#include "server.h"

direct_message_t *add_direct_message(
    my_teams_t *my_teams, char uuid1[UUID_STR_LEN], char uuid2[UUID_STR_LEN])
{
    if ((my_teams->list_of_direct_message = malloc(sizeof(direct_message_t)))
        == NULL)
        return NULL;
    memset(my_teams->list_of_direct_message, 0, sizeof(direct_message_t));
    strcpy(my_teams->list_of_direct_message->uuid1, uuid1);
    strcpy(my_teams->list_of_direct_message->uuid2, uuid2);
    my_teams->list_of_direct_message->list_of_message =
        init_conversation(my_teams->list_of_direct_message);
    TAILQ_INSERT_HEAD(&my_teams->direct_message_head,
        my_teams->list_of_direct_message, next_direct_message);
    printf("add new team: [%s] [%s] \n",
        my_teams->list_of_direct_message->uuid1,
        my_teams->list_of_direct_message->uuid2);
    return my_teams->list_of_direct_message;
}
