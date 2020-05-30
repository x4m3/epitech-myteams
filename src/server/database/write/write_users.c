/*
** EPITECH PROJECT, 2020
** epitech-myteams
** File description:
** write_users
*/

#include "database.h"
#include "server.h"

static void store_user_data(FILE *output, user_info_t *user)
{
    fprintf(output, "UUID=%s\n", user->user_uuid);
    fprintf(output, "USERNAME=%s\n", user->username);
}

static bool write_user(user_info_t *user, const char *filepath)
{
    FILE *output = open_file_write(filepath);

    if (output == NULL)
        return false;
    store_user_data(output, user);
    fclose(output);
    return true;
}

bool write_users(my_teams_t *my_teams)
{
    char *filename = NULL;
    char *filepath = NULL;
    bool ret = false;

    TAILQ_FOREACH(my_teams->users, &my_teams->user_info_head, next_users)
    {
        filename = construct_filename(my_teams->users->user_uuid, USER);
        if (filename == NULL)
            return false;
        filepath = construct_filepath(DB_USERS_PATH, filename);
        if (filepath == NULL) {
            free(filename);
            return false;
        }
        ret = write_user(my_teams->users, filepath);
        free(filepath);
        if (ret == false)
            return false;
    }
    return true;
}
