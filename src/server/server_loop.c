/*
** EPITECH PROJECT, 2020
** epitech-myteams
** File description:
** server_loop
*/

#include <signal.h>
#include "server.h"

static void update_clients(server_t *server)
{
    int current = 0;
    bool ret = 0;

    for (size_t i = 0; i < FD_SETSIZE; i++) {
        current = server->net_users[i].socket_fd;
        if (FD_ISSET(current, &server->read)) {
            ret = client_handle(&server->net_users[i]);
            if (ret == false) {
                if (server->net_users[i].user != NULL)
                    delete_one_instance(server->net_users[i].user, current);
                printf("[%d]: bye bye\n", server->net_users[i].socket_fd);
                client_delete(&(server->net_users[i]));
            }
        }
    }
}

static bool network_handling(server_t *server)
{
    int client_socket_fd = 0;

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
        return false;
    if (client_init(server) == false)
        return false;
    update_clients(server);
    return true;
}

static void sighandler(__attribute__((unused)) int sig)
{
    stay_alive(0);
    printf("    Ah, ha, ha, ha, stayin' alive, stayin' alive (rip)\n");
}

void server_loop(server_t *server)
{
    stay_alive(1);
    signal(SIGINT, &sighandler);
    while (stay_alive(-1) == true) {
        if (network_handling(server) == false)
            return;
    }
}
