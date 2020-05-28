/*
** EPITECH PROJECT, 2020
** epitech-myteams
** File description:
** server_loop
*/

#include "server.h"

static void update_clients(server_t *server)
{
    int current = 0;
    bool ret = 0;

    for (size_t i = 0; i < FD_SETSIZE; i++) {
        current = server->net_users[i].socket_fd;
        if (FD_ISSET(current, &server->read)) {
            ret = client_handle(&server->net_users[i]);
            // TODO: check if instance is disconnected
            // if (ret == false || server->net_users[i].user->online == false)
            if (ret == false) {
                printf("current instance %p\n",
                    server->net_users[i].user->list_of_instance);
                delete_one_instance(server->net_users[i].user, current);
                printf("[%d]: bye bye\n", server->net_users[i].socket_fd);
            }
        }
    }
}

void server_loop(server_t *server)
{
    int client_socket_fd = 0;

    while (1) {
        // TODO: handle SIGINT signal
        FD_ZERO(&server->active);
        FD_SET(server->socket_fd, &server->active);
        for (size_t i = 0; i < FD_SETSIZE; i++) {
            client_socket_fd = server->net_users[i].socket_fd;
            if (client_socket_fd > 0)
                FD_SET(client_socket_fd, &server->active);
            if (client_socket_fd > server->max_fd)
                server->max_fd = client_socket_fd;
        }
        server->read = server->active;
        if (select(server->max_fd + 1, &server->read, NULL, NULL, NULL) < 0)
            return;
        if (client_init(server) == false)
            return;
        update_clients(server);
    }
}
