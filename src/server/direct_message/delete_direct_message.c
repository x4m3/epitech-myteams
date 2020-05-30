/*
** EPITECH PROJECT, 2019
** name of the project
** File description:
** foo
*/

#include "server.h"

void delete_direct_message(my_teams_t *myteams)
{
    while (myteams->direct_message_head.tqh_first != NULL) {
        myteams->list_of_direct_message =
            TAILQ_FIRST(&myteams->direct_message_head);
        TAILQ_REMOVE(&myteams->direct_message_head,
            myteams->direct_message_head.tqh_first, next_direct_message);
        delete_conversation(myteams->list_of_direct_message);
        if (myteams->list_of_direct_message != NULL)
            free(myteams->list_of_direct_message);
    }
}
