/*
** EPITECH PROJECT, 2019
** name of the project
** File description:
** foo
*/

#include "server.h"

void list_user(my_teams_t *myTeams)
{
    TAILQ_FOREACH(myTeams->users, &myTeams->user_info_head, next_users)
    {
        printf("%s %s :", myTeams->users->username,
            myTeams->users->user_uuid);
        if (myTeams->users->online == true)
            printf("online\n");
        else
            printf("not online\n");
    }
}
