/*
** EPITECH PROJECT, 2020
** epitech-myteams
** File description:
** open_file_write
*/

#include <stdio.h>

FILE *open_file_write(const char *file_path)
{
    FILE *file = fopen(file_path, "w");

    if (file == NULL) {
        printf("[database]  failed to open [%s] for writing.\n", file_path);
        return NULL;
    }
    printf("[database]  file [%s] is open for writing.\n", file_path);
    return file;
}
