/*
** EPITECH PROJECT, 2019
** name of the project
** File description:
** foo
*/

#include "server.h"

user_info_t *init_user_info(my_teams_t *myteam)
{
    TAILQ_INIT(&myteam->user_info_head);
    return myteam->users;
}
