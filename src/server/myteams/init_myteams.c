/*
** EPITECH PROJECT, 2019
** name of the project
** File description:
** foo
*/

#include "server.h"

my_teams_t *init_my_teams(void)
{
    my_teams_t *my_teams;

    if ((my_teams = malloc(sizeof(my_teams_t))) == NULL)
        return NULL;
    memset(my_teams, 0, sizeof(my_teams_t));
    init_team(my_teams);
    //  init_message();
    return my_teams;
}