/*
** EPITECH PROJECT, 2020
** epitech-myteams
** File description:
** remove_end_of_line
*/

#include <stdbool.h>
#include <stddef.h>

bool remove_end_of_line(char *str)
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
