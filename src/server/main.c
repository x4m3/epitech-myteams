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

static void cleanup(server_t *server)
{
    delete_myteams(server->my_teams);
    free(server->net_users);
    free(server);
}

static void my_teams(char **av)
{
    server_t *server = NULL;

    server = server_init(av);
    if (server == NULL)
        return display_usage(av[0], 84);
    server_loop(server);
    printf("preparing to exit: saving server data\n");
    write_all(server->my_teams);
    printf("starting to cleanup memory\n");
    cleanup(server);
    printf("that's all folks!\n");
}

int main(int ac, char **av)
{
    if (ac != 2)
        return display_usage(av[0], 84);
    if (strcmp(av[1], "-help") == 0)
        return display_usage(av[0], 0);
    my_teams(av);
    return 0;
}
