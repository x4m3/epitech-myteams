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
#include "logging_client.h"

typedef enum cmd_list {
    NONE = 0,
    LOGIN,
    LOGOUT,
    HELP,
    USERS,
    USER,
    SEND,
    MESSAGES,
    SUBSCRIBE,
    SUBSCRIBED,
    UNSUB,
    USE,
    CREATE,
    LIST,
    INFO
} cmd_list_e;

typedef struct command_s {
    char *cmd;
    cmd_list_e c;
    char **args;
} command_t;

typedef struct client_s {
    int sockFd;
    struct sockaddr_in sockaddrIn;
} client_t;

void manage_client_serv_com(client_t *client);
void parse_args_from_response(char *response, command_t *cmd);
#endif // EPITECH_MYTEAMS_CLIENT_H
