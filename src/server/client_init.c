/*
** EPITECH PROJECT, 2020
** epitech-myteams
** File description:
** client_init
*/

#include <arpa/inet.h> /* for inet_ntoa */
#include <stdio.h>     /* for fdopen */
#include <string.h>    /* for strdup */
#include "server.h"

static bool store_new_client(int new_client, server_t *server)
{
    for (size_t i = 0; i < FD_SETSIZE; i++) {
        if (server->net_users[i].socket_fd == 0) {
            server->net_users[i].socket_fd = new_client;
            server->net_users[i].user = NULL;
            server->net_users[i].input = fdopen(new_client, "r");
            if (server->net_users[i].input == NULL)
                return false;
            return true;
        }
    }
    return false;
}

bool client_init(server_t *server)
{
    struct sockaddr_in client_addr;
    unsigned int size = sizeof(client_addr);
    int new_client = 0;

    if (FD_ISSET(server->socket_fd, &server->read)) {
        new_client =
            accept(server->socket_fd, (struct sockaddr *) &client_addr, &size);
        if (new_client < 0 || store_new_client(new_client, server) == false)
            return false;
        printf("[%d]: new client: %s\n", new_client,
            inet_ntoa(client_addr.sin_addr));
        dprintf(new_client, "welcome to the my_teams server\n");
    }
    return true;
}
