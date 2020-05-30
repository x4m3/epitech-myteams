/*
** EPITECH PROJECT, 2020
** epitech-myteams
** File description:
** construct_filepath
*/

#include <stdlib.h>
#include <string.h>

char *construct_filepath(char *base_path, char *filename)
{
    size_t i = 0;
    char *str =
        malloc(sizeof(char) * (strlen(base_path) + strlen(filename) + 1));

    if (str == NULL)
        return NULL;
    for (; base_path[i] != 0; i++)
        str[i] = base_path[i];
    str[i] = '/';
    for (size_t j = 0; filename[j] != 0; i++, j++)
        str[i] = filename[j];
    str[i] = 0;
    free(filename);
    return str;
}
