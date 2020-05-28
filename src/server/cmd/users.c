/*
** EPITECH PROJECT, 2020
** epitech-myteams
** File description:
** users
*/

#include "server.h"

void cmd_users(net_user_t *user)
{
    my_teams_t *global_teams = get_global_teams(NULL);

    list_user(global_teams, user->socket_fd);
}
