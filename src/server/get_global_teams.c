/*
** EPITECH PROJECT, 2020
** epitech-myteams
** File description:
** get_global_teams
*/

#include "server.h"

my_teams_t *get_global_teams(my_teams_t *new)
{
    static my_teams_t *global;

    if (new != NULL)
        global = new;
    return global;
}
