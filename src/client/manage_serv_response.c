/*
** EPITECH PROJECT, 2020
** epitech-myteams
** File description:
** client
*/

#include "client.h"
#include "myteams.h"

static void remove_end_of_line(char *str)
{
    size_t pos_end_of_line = 0;

    if (str == NULL)
        return;
    for (size_t i = 0; str[i]; i++)
        if (str[i] == '\n')
            pos_end_of_line = i;
    if (pos_end_of_line != 0)
        str[pos_end_of_line] = 0;
}

static void handle_messages(int sockFd)
{
    char *buffer = NULL;
    size_t size;
    FILE *stream = fdopen(sockFd, "r");

    if (stream == NULL) {
        perror("fdopen error\n");
        return;
    }
    getline(&buffer, &size, stream);
    remove_end_of_line(buffer);
    printf("%s\n", buffer);
    free(buffer);
    // parse message and do actions w/ lib
}

static void send_messages(client_t *client, char *line)
{
    send(client->sockFd, line, strlen(line), 0);
}

void manage_client_serv_com(client_t *client)
{
    fd_set current_sock;
    fd_set ready_sock;
    char *line = NULL;
    size_t size;

    FD_ZERO(&current_sock);
    FD_SET(client->sockFd, &current_sock);
    while (1) {
        ready_sock = current_sock;
        if (select(client->sockFd + 1, &ready_sock, NULL, NULL, NULL) < 0)
            exit(EXIT_FAILURE);
        if (FD_ISSET(client->sockFd, &ready_sock))
            handle_messages(client->sockFd);
        if (FD_ISSET(client->sockFd, &ready_sock))
            getline(&line, &size, stdin);
        if (FD_ISSET(client->sockFd, &ready_sock))
            send_messages(client, line);
        if (line)
            free(line);
    }
}
