/*
** EPITECH PROJECT, 2019
** name of the project
** File description:
** foo
*/

#include "server.h"

void delete_myteams(my_teams_t *myteams)
{
    delete_user_info(myteams);
    delete_team(myteams);
    delete_direct_message(myteams);
    if (myteams != NULL)
        free(myteams);
}
