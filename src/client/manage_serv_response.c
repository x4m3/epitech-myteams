/*
** EPITECH PROJECT, 2020
** epitech-myteams
** File description:
** client
*/

#include "client.h"
#include "myteams.h"

static void handle_messages_from_server(int sockFd)
{
    int size = 0;
    char *buffer = malloc(sizeof(char) * MAX_BODY_LENGTH);
    size = read(sockFd, buffer, sizeof(buffer));
    if (size <= 0) {
        perror("Failed reading socket\n");
        return;
    }
    buffer[size] = '\0';
    write(1, buffer, strlen(buffer));
}

void check_and_read_fd(client_t *client)
{
    fd_set current_sock;
    fd_set ready_sock;

    FD_ZERO(&current_sock);
    FD_SET(client->sockFd, &current_sock);

    while (1) {
        ready_sock = current_sock;
        if (select(FD_SETSIZE, &ready_sock, NULL, NULL, NULL) < 0) {
            perror("select function error");
            exit(EXIT_FAILURE);
        }
        for (int i = 0; i < FD_SETSIZE; i++) {
            (FD_ISSET(i, &ready_sock)) ?
                                       (handle_messages_from_server(i)) : (i
                                           = i);
        }
    }
}