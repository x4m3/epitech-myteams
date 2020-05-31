/*
** EPITECH PROJECT, 2020
** epitech-myteams
** File description:
** load_all
*/

#include <sys/stat.h>
#include "database.h"
#include "server.h"

bool check_folder(void)
{
    struct stat st = {0};

    if (stat(DB_ROOT_PATH, &st) == -1) {
        printf("[database]  database does not exist, not loading\n");
        return false;
    }
    printf("[database]  found database, starting to load\n");
    return true;
}

bool load_all(my_teams_t *my_teams)
{
    if (check_folder() == false)
        return false;
    load_users(my_teams);
    printf("[database]  database has been loaded\n");
    return true;
}
