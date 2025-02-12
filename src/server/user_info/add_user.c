/*
** EPITECH PROJECT, 2019
** name of the project
** File description:
** foo
*/

#include "server.h"

user_info_t *add_user(my_teams_t *myTeams, char *username, char *user_uuid)
{
    uuid_t new_uuid_bin;

    if ((myTeams->users = malloc(sizeof(user_info_t))) == NULL)
        return NULL;
    memset(myTeams->users, 0, sizeof(user_info_t));
    if (user_uuid == NULL) {
        uuid_generate_random(new_uuid_bin);
        uuid_unparse(new_uuid_bin, myTeams->users->user_uuid);
    } else
        strcpy(myTeams->users->user_uuid, user_uuid);
    strcpy(myTeams->users->username, username);
    TAILQ_INSERT_HEAD(&(myTeams->user_info_head), myTeams->users, next_users);
    printf("add new user: [%s] [%s]\n", myTeams->users->username,
        myTeams->users->user_uuid);
    (user_uuid == NULL) ? server_event_user_created(
        myTeams->users->user_uuid, myTeams->users->username)
                        : server_event_user_loaded(myTeams->users->user_uuid,
                            myTeams->users->username);
    return myTeams->users;
}
