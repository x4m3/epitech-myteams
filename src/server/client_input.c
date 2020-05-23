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

char **client_input(FILE *input, char *buffer)
{
    char **array = NULL;
    size_t len = 0;

    if (getline(&buffer, &len, input) == -1)
        return NULL;
    if (remove_end_of_line(buffer) == false)
        return NULL;
    array = malloc(sizeof(char *) * (4 + 1));
    if (array == NULL) {
        free(buffer);
        return NULL;
    }
    array[0] = strtok(buffer, " ");
    for (size_t i = 1; i < 4; i++)
        array[i] = strtok(NULL, " ");
    array[4] = NULL;
    return array;
}
