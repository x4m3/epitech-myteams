/*
** EPITECH PROJECT, 2019
** name of the project
** File description:
** foo
*/

#include "server.h"

user_info_t *add_user(my_teams_t *myTeams, char *username)
{
    //    user_info_t *new_user;
    uuid_t new_uuid_bin;

    if ((myTeams->users = malloc(sizeof(user_info_t))) == NULL)
        return NULL;
    uuid_generate_random(new_uuid_bin);
    uuid_unparse(new_uuid_bin, myTeams->users->user_uuid);
    strcpy(myTeams->users->username, username);
    printf("head %p\n", &myTeams->user_info_head.tqh_last);
    printf("head first %p\n", &myTeams->user_info_head.tqh_first);
    printf("new user %p\n", &myTeams->users->next_users);

    TAILQ_INSERT_HEAD(&(myTeams->user_info_head), myTeams->users, next_users);

    // printf(
    //    "add new user: [%s] [%s]\n", new_user->username,
    //    new_user->user_uuid);
    // server_event_user_created(new_user->user_uuid, new_user->username);
    return myTeams->users;
}
