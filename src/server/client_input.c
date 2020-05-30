/*
** EPITECH PROJECT, 2020
** epitech-myteams
** File description:
** client_input
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static bool remove_end_of_line(char *str)
{
    size_t pos_end_of_line = 0;

    if (str == NULL)
        return false;
    for (size_t i = 0; str[i]; i++)
        if (str[i] == '\n')
            pos_end_of_line = i;
    if (pos_end_of_line != 0)
        str[pos_end_of_line] = 0;
    return true;
}

static char *get_cmd(char **buffer, size_t *offset)
{
    char *raw = *buffer;
    char *str = NULL;
    size_t len_raw = 0;

    while (raw[len_raw] != 0 && raw[len_raw] != ' ')
        len_raw++;
    str = malloc(sizeof(char) * (len_raw + 1));
    if (str == NULL)
        return NULL;
    for (size_t i = 0; i < len_raw; i++)
        str[i] = raw[i];
    str[len_raw] = 0;
    *offset = (len_raw + 1);
    *buffer += *offset;
    return str;
}

static char *get_param(char **buffer, size_t *offset)
{
    char *raw = *buffer;
    char *str = NULL;
    size_t len_raw = 0;
    bool the_end = true;
    size_t local_offset = 0;

    if (*raw != '"')
        return NULL;
    raw++;
    while (raw[len_raw] != 0 && raw[len_raw] != '"')
        len_raw++;
    the_end = (raw[++len_raw] == ' ') ? false : true;
    len_raw--;
    str = malloc(sizeof(char) * (len_raw + 1));
    if (str == NULL)
        return NULL;
    for (size_t i = 0; i < len_raw; i++)
        str[i] = raw[i];
    str[len_raw] = 0;
    local_offset = (len_raw + ((the_end == false) ? 3 : 2));
    *offset += local_offset;
    *buffer += local_offset;
    return str;
}

char **client_input(FILE *input)
{
    char **array = NULL;
    char *getline_buffer = NULL;
    char *buffer = NULL;
    size_t len = 0;
    size_t offset = 0;

    if (getline(&getline_buffer, &len, input) == -1)
        return NULL;
    if (remove_end_of_line(getline_buffer) == false)
        return NULL;
    buffer = strdup(getline_buffer);
    free(getline_buffer);
    array = malloc(sizeof(char *) * (4 + 1));
    array[0] = get_cmd(&buffer, &offset);
    for (size_t i = 1; i < 4; i++)
        array[i] = get_param(&buffer, &offset);
    array[4] = NULL;
    buffer -= offset;
    free(buffer);
    return array;
}
