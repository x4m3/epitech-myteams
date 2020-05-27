/*
** EPITECH PROJECT, 2020
** epitech-myteams
** File description:
** remove_quotes
*/

#include <stddef.h>
#include <stdlib.h>
#include <string.h>

/**
** remove the quotes from a string
** @param source
** @return
**
** malloc: length of orig string - 2 (the 2 quotes)
**
** we *ASSUME* that the first quote is at position [0]
** and the last one is that position [strlen]
*/
char *remove_quotes(const char *source)
{
    size_t i = strlen(source) - 2;
    char *str = malloc(sizeof(char) * (i + 1));

    if (str == NULL)
        return NULL;
    source++;
    strncpy(str, source, i);
    str[i] = 0;
    return str;
}
