/*
** EPITECH PROJECT, 2020
** epitech-myteams
** File description:
** construct_filename
*/

#include <stdlib.h>
#include <string.h>
#include "database.h"

static void fill_ext(char *ext, char *name, size_t *pos)
{
    for (size_t i = 0; ext[i]; i++) {
        (*pos)++;
        name[*pos] = ext[i];
    }
}

char *construct_filename(char *name, file_extension_e ext)
{
    size_t i = 0;
    char *str = malloc(sizeof(char) * (strlen(name) + ext) + 1);

    if (str == NULL)
        return NULL;
    for (; name[i]; i++)
        str[i] = name[i];
    str[i] = '.';
    switch (ext) {
        case USER: fill_ext("user", str, &i); break;
        case PRIVATE_MSG: fill_ext("private_msg", str, &i); break;
        case TEAM: fill_ext("team", str, &i); break;
        case CHANNEL: fill_ext("channel", str, &i); break;
        case THREAD: fill_ext("thread", str, &i); break;
        default: break;
    }
    i++;
    str[i] = 0;
    return str;
}
