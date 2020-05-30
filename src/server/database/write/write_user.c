/*
** EPITECH PROJECT, 2020
** epitech-myteams
** File description:
** write_user
*/

#include "database.h"
#include "server.h"

bool write_user(user_info_t *user)
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
    return true;
}
