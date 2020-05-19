/*
** EPITECH PROJECT, 2020
** epitech-myteams
** File description:
** main
*/

#include <stdio.h> /* for printf */
#include <string.h> /* for strcmp */

static int display_usage(const char *bin, const int ret)
{
    printf("USAGE: %s port\n\n", bin);
    printf("\t port is the port number on which the server socket listens.\n");
    return ret;
}

int main(int ac, char **av)
{
    if (ac != 2)
        return display_usage(av[0], 84);
    if (strcmp(av[1], "-help") == 0)
        return display_usage(av[0], 0);
    return 0;
}
