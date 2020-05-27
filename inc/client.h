/*
** EPITECH PROJECT, 2020
** epitech_myteams
** File description:
** TODO: add description
*/

#ifndef EPITECH_MYTEAMS_CLIENT_H
#define EPITECH_MYTEAMS_CLIENT_H

#include <sys/socket.h>
#include <netdb.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>

typedef struct client_s {
    int sockFd;
    struct sockaddr_in sockaddrIn;
} client_t;

#endif // EPITECH_MYTEAMS_CLIENT_H
