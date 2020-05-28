/*
** EPITECH PROJECT, 2019
** name of the project
** File description:
** foo
*/

#include "server.h"

void list_private_message(char author[UUID_STR_LEN], my_teams_t *myTeams)
{
    TAILQ_FOREACH(
        myTeams->list_of_message, &myTeams->message_head, next_message)
    {
        if (strcmp(myTeams->list_of_message->author, author) == 0)
            printf("%ld %s : %s", myTeams->list_of_message->creation_date,
                myTeams->list_of_message->author,
                myTeams->list_of_message->body_message);
    }
}
