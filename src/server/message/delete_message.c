/*
** EPITECH PROJECT, 2019
** name of the project
** File description:
** foo
*/

#include "server.h"

static void delete_msg_thread(thread_t *thread)
{
    while (thread->message_head.tqh_first != NULL) {
        thread->list_of_message = TAILQ_FIRST(&thread->message_head);
        TAILQ_REMOVE(&thread->message_head, thread->message_head.tqh_first,
            next_message);
        free(thread->list_of_message);
    }
    if (thread->list_of_message != NULL)
        free(thread->list_of_message);
}

static void delete_msg_teams(my_teams_t *myteams)
{
    while (myteams->message_head.tqh_first != NULL) {
        myteams->list_of_message = TAILQ_FIRST(&myteams->message_head);
        TAILQ_REMOVE(&myteams->message_head, myteams->message_head.tqh_first,
            next_message);
        free(myteams->list_of_message);
    }
    if (myteams->list_of_message != NULL)
        free(myteams->list_of_message);
}

void delete_message(void *ptr, char c)
{
    if (c == 't')
        return delete_msg_thread((thread_t *) ptr);
    return delete_msg_teams((my_teams_t *) ptr);
}
