/*
** EPITECH PROJECT, 2019
** name of the project
** File description:
** foo
*/

#include "server.h"

void delete_myteams(my_teams_t *myteams)
{
    //TODO delete user_info
    delete_team(myteams->list_of_team);
    //delete_message()
}
