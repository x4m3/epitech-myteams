/*
** EPITECH PROJECT, 2020
** epitech-myteams
** File description:
** load_user
*/

#include <dirent.h>
#include <stdbool.h>
#include <stdio.h>
#include "database.h"

bool load_users(my_teams_t *my_teams)
{
    struct dirent *dir_dirent = NULL;
    DIR *directory = opendir(DB_USERS_PATH);

    if (directory == NULL)
        return false;
    while ((dir_dirent = readdir(directory)) != NULL) {
        if (dir_dirent->d_type != DT_REG)
            continue;
        printf("%s\n", dir_dirent->d_name);
    }
    closedir(directory);
    return true;
}
