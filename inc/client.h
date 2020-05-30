/*
** EPITECH PROJECT, 2020
** epitech_myteams
** File description:
** TODO: add description
*/

#ifndef EPITECH_MYTEAMS_CLIENT_H
#define EPITECH_MYTEAMS_CLIENT_H

#include <arpa/inet.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

typedef struct client_s {
    int sockFd;
    struct sockaddr_in sockaddrIn;
} client_t;

void manage_client_serv_com(client_t *client);

#endif // EPITECH_MYTEAMS_CLIENT_H
