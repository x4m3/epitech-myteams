/*
** EPITECH PROJECT, 2019
** name of the project
** File description:
** foo
*/

#include "server.h"

void list_user(my_teams_t *my_teams, int socket_user)
{
    char *param_to_send_cli = NULL;

    TAILQ_FOREACH(my_teams->users, &my_teams->user_info_head, next_users)
    {
        param_to_send_cli = concat_args_to_cli(
            my_teams->users->user_uuid, my_teams->users->username,
            (my_teams->users->online == true) ? "0" : "1", NULL);
        client_response(socket_user, param_to_send_cli);
        free(param_to_send_cli);
    }
}

void list_user_internal(my_teams_t *myTeams)
{
    printf("[list_user_internal] start\n");
    TAILQ_FOREACH(myTeams->users, &myTeams->user_info_head, next_users)
    {
        printf("uuid [%s]  username [%s]\n", myTeams->users->user_uuid,
            myTeams->users->username);
    }
    printf("[list_user_internal] end\n");
}
