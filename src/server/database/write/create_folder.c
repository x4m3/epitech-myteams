/*
** EPITECH PROJECT, 2020
** epitech-myteams
** File description:
** create
*/

#include <stdbool.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

bool create_folder(const char *folder_path)
{
    struct stat st = {0};

    if (stat(folder_path, &st) == -1) {
        mkdir(folder_path, 0775);
        return true;
    }
    return false;
}
