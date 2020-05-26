/*
** EPITECH PROJECT, 2020
** epitech-myteams
** File description:
** main
*/

#include <stdio.h>  /* for printf */
#include <string.h> /* for strcmp */
#include "server.h"

static int display_usage(const char *bin, const int ret)
{
    printf("USAGE: %s port\n\n", bin);
    printf("\t port is the port number on which the server socket listens.\n");
    return ret;
}

int main(int ac, char **av)
{
    server_t *server = NULL;
    my_teams_t *myTeams;
    if (ac != 2)
        return display_usage(av[0], 84);
    if (strcmp(av[1], "-help") == 0)
        return display_usage(av[0], 0);

    server = server_init(av);
    if (server == NULL)
        return display_usage(av[0], 84);
    myTeams = init_my_teams();
    if (myTeams == NULL)
        return 84;
    server_loop(server);
    delete_myteams(myTeams);
    // TODO: save information and cleanup
    return 0;
}
