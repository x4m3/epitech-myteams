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
#include "shared.h"

static void load_user_data(my_teams_t *my_teams)
{
}

static void get_content(FILE *input, my_teams_t *my_teams)
{
    char *buffer = NULL;
    size_t len = 0;

    while (getline(&buffer, &len, input) != -1) {
        remove_end_of_line(buffer);
        printf("[%s]\n", buffer);
    }
    free(buffer);
}

static bool load_user(my_teams_t *my_teams, char *filename)
{
    char *filepath = construct_filepath(DB_USERS_PATH, filename);
    FILE *input = NULL;

    if (filepath == NULL)
        return false;
    input = open_file_read(filepath);
    if (input == NULL)
        return false;
    get_content(input, my_teams);
    free(filepath);
    fclose(input);
    return true;
}

bool load_users(my_teams_t *my_teams)
{
    struct dirent *dir_dirent = NULL;
    DIR *directory = opendir(DB_USERS_PATH);

    if (directory == NULL)
        return false;
    while ((dir_dirent = readdir(directory)) != NULL) {
        if (dir_dirent->d_type != DT_REG)
            continue;
        load_user(my_teams, dir_dirent->d_name);
    }
    closedir(directory);
    return true;
}
