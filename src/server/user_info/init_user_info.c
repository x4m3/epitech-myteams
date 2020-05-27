/*
** EPITECH PROJECT, 2019
** name of the project
** File description:
** foo
*/

#include "server.h"

user_info_t *init_user_info(my_teams_t *myteam)
{
    if ((myteam->users = malloc(sizeof(user_info_t))) == NULL)
        return NULL;
    memset(myteam->users, 0, sizeof(user_info_t));
    TAILQ_INIT(&myteam->user_info_head);
    //init_instance(myteam->users);
    return myteam->users;
}
