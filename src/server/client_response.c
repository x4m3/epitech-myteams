/*
** EPITECH PROJECT, 2020
** epitech-myteams
** File description:
** client_response
*/

#include <stdio.h>

void client_response(int output, const char *str)
{
    printf("[%d]: %s\n", output, str);
    dprintf(output, "%s\n", str);
}
