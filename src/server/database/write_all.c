/*
** EPITECH PROJECT, 2020
** epitech-myteams
** File description:
** write_all
*/

#include "database.h"
#include "server.h"

static void create_folders(void)
{
    printf("[database]  creating folders\n");
    recursive_mkdir(DB_USERS_PATH);
    recursive_mkdir(DB_PRIVATE_PATH);
}

bool write_all(my_teams_t *my_teams)
{
    create_folders();
    write_users(my_teams);
    return true;
}
