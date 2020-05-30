/*
** EPITECH PROJECT, 2020
** epitech-myteams
** File description:
** write_users
*/

#include "database.h"
#include "server.h"

static bool write_user(user_info_t *user)
{
    FILE *output = NULL;
    char *filename = construct_filename(user->user_uuid, USER);
    char *filepath = NULL;

    if (filename == NULL)
        return false;
    filepath = construct_filepath(DB_USERS_PATH, filename);
    if (filepath == NULL) {
        free(filename);
        return false;
    }
    printf("filepath: [%s]\n", filepath);
    free(filepath);
    return true;
}

bool write_users(my_teams_t *my_teams)
{
    TAILQ_FOREACH(my_teams->users, &my_teams->user_info_head, next_users)
    {
        write_user(my_teams->users);
    }
    return true;
}
