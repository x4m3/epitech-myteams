/*
** EPITECH PROJECT, 2019
** name of the project
** File description:
** foo
*/

#include "server.h"

void list_user(my_teams_t *myTeams, int socket_user)
{
    TAILQ_FOREACH(myTeams->users, &myTeams->user_info_head, next_users)
    {
        client_response(socket_user, myTeams->users->username);
        client_response(socket_user, myTeams->users->user_uuid);
        if (myTeams->users->online == true)
            client_response(socket_user, "online");
        else
            client_response(socket_user, "not online");
    }
}
