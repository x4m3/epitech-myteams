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
    printf("add new message: [%s] [%s]\n", thread->list_of_message->author,
        thread->list_of_message->body_message);
    return thread->list_of_message;
}

message_t *add_private_message(char message[MAX_BODY_LENGTH], char author[UUID_STR_LEN], my_teams_t *myTeams)
{
    time_t now = time(NULL);

    if ((myTeams->list_of_message = malloc(sizeof(team_t))) == NULL)
        return NULL;
    strcpy(myTeams->list_of_message->author, author);
    strcpy(myTeams->list_of_message->body_message, message);
    myTeams->list_of_message->creation_date = now;
    TAILQ_INSERT_HEAD(
        &myTeams->message_head, myTeams->list_of_message, next_message);
    printf("add new message: [%s] [%s]\n", myTeams->list_of_message->author,
        myTeams->list_of_message->body_message);
    return myTeams->list_of_message;

}
