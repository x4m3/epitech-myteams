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

static char *get_cmd(char *raw, size_t *len_cmd)
{
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
    *len_cmd = (len_raw + 1);
    return str;
}

char **client_input(FILE *input, char *buffer)
{
    char **array = NULL;
    size_t len = 0;
    size_t len_cmd = 0;

    if (getline(&buffer, &len, input) == -1)
        return NULL;
    if (remove_end_of_line(buffer) == false)
        return NULL;
    array = malloc(sizeof(char *) * (4 + 1));
    if (array == NULL) {
        free(buffer);
        return NULL;
    }
    printf("before get_cmd: [%s]\n", buffer);
    array[0] = get_cmd(buffer, &len_cmd);
    if (array[0] == NULL) {
        free(buffer);
        free(array);
        return NULL;
    }
    buffer += len_cmd;
    printf("after get_cmd: [%s]\n", buffer);
    for (size_t i = 1; i < 4; i++) {
        // TODO: parsing of the command with quotes
        array[i] = NULL;
    }
    array[4] = NULL;
    return array;
}
