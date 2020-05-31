/*
** EPITECH PROJECT, 2020
** epitech-myteams
** File description:
** open_file_read
*/

#include <stdio.h>

FILE *open_file_read(const char *file_path)
{
    FILE *file = fopen(file_path, "r");

    if (file == NULL) {
        printf("[database]  failed to open [%s] for reading.\n", file_path);
        return NULL;
    }
    printf("[database]  file [%s] is open for reading.\n", file_path);
    return file;
}
