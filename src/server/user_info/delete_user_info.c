/*
** EPITECH PROJECT, 2019
** name of the project
** File description:
** foo
*/

#include "server.h"

void delete_user_info(my_teams_t *myteams)
{
    while (myteams->user_info_head.tqh_first != NULL) {
        myteams->users = TAILQ_FIRST(&myteams->user_info_head);
        TAILQ_REMOVE(&myteams->user_info_head,
            myteams->user_info_head.tqh_first, next_users);
        free(myteams->list_of_team);
    }
}
