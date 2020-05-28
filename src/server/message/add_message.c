/*
** EPITECH PROJECT, 2019
** name of the project
** File description:
** foo
*/

#include "server.h"

message_t *add_reply(
    char message[MAX_BODY_LENGTH], char author[UUID_STR_LEN], thread_t *thread)
{
    time_t now = time(NULL);

    if ((thread->list_of_message = malloc(sizeof(team_t))) == NULL)
        return NULL;
    strcpy(thread->list_of_message->author, author);
    strcpy(thread->list_of_message->body_message, message);
    thread->list_of_message->creation_date = now;
    TAILQ_INSERT_HEAD(
        &thread->message_head, thread->list_of_message, next_message);
    printf("add new thread: [%s] [%s]\n", thread->list_of_message->author,
        thread->list_of_message->body_message);
    return thread->list_of_message;
}
