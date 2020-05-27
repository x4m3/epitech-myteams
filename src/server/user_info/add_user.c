/*
** EPITECH PROJECT, 2019
** name of the project
** File description:
** foo
*/

#include "server.h"

user_info_t *add_user(my_teams_t *myTeams, char *username)
{
    user_info_t *new_user;
    uuid_t new_uuid_bin;

    if ((new_user = malloc(sizeof(user_info_t))) == NULL)
        return NULL;
    uuid_generate_random(new_uuid_bin);
    uuid_unparse(new_uuid_bin, new_user->user_uuid);
    strcpy(new_user->username, username);
    TAILQ_INSERT_TAIL(&myTeams->user_info_head, new_user, next_users);
    printf(
        "add new user: [%s] [%s]\n", new_user->username, new_user->user_uuid);
    server_event_user_created(new_user->user_uuid, new_user->username);
    return new_user;
}
