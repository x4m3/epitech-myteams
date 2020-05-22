/*
** EPITECH PROJECT, 2020
** epitech_myteams
** File description:
** server_init
*/

#include <stdlib.h> /* for malloc */
#include <string.h> /* for memset */
#include "server.h"

#define SERVER_QUEUE 10

static bool server_socket_creation(server_t *server, int port)
{
    int optval = 1;

    memset(&(server->addr), 0, sizeof(server->addr));
    server->addr.sin_family = AF_INET;
    server->addr.sin_port = htons(port);
    server->addr.sin_addr.s_addr = INADDR_ANY;
    server->socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server->socket_fd < 0)
        return false;
    setsockopt(
        server->socket_fd, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval));
    if (bind(server->socket_fd, (struct sockaddr *) &(server->addr),
            sizeof(server->addr))
        < 0)
        return false;
    listen(server->socket_fd, SERVER_QUEUE);
    server->max_fd = server->socket_fd;
    return true;
}

static server_t *mem_alloc(void)
{
    server_t *server = malloc(sizeof(server_t));

    if (server == NULL)
        return NULL;
    server->my_teams = malloc(sizeof(my_teams_t));
    if (server->my_teams == NULL) {
        free(server);
        return NULL;
    }
    server->net_users = malloc(sizeof(net_user_t) * FD_SETSIZE);
    if (server->net_users == NULL) {
        free(server->my_teams);
        free(server);
        return NULL;
    }
    memset(server->my_teams, 0, sizeof(my_teams_t));
    memset(server->net_users, 0, sizeof(net_user_t) * FD_SETSIZE);
    return server;
}

server_t *server_init(char **av)
{
    server_t *server = mem_alloc();
    bool ret_socket_creation = false;

    if (server == NULL)
        return NULL;
    ret_socket_creation = server_socket_creation(server, atoi(av[1]));
    if (ret_socket_creation == false) {
        free(server->my_teams);
        free(server);
        return NULL;
    }
    return server;
}
