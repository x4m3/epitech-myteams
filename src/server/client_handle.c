/*
** EPITECH PROJECT, 2020
** epitech-myteams
** File description:
** client_handle
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cmd.h"
#include "server.h"

static void process_input(net_user_t *net_user, char **input)
{
    size_t i = 0;

    if (input[0] == NULL)
        client_response(net_user->socket_fd, "command not found");
    for (; commands[i].name != NULL; i++) {
        if (strcmp(commands[i].name, input[0]) == 0)
            break;
    }
    if (commands[i].name == NULL)
        return client_response(net_user->socket_fd, "command not found");
    if (strcmp(commands[i].name, "/help") != 0
        && strcmp(commands[i].name, "/login") != 0) {
        if (net_user->user == NULL || net_user->user->online == false)
            return client_response(net_user->socket_fd, "not logged in\n");
    }
    (commands[i].func)(net_user, input);
}

bool client_handle(net_user_t *net_user)
{
    char **array = client_input(net_user->input);

    if (array == NULL) {
        client_response(net_user->socket_fd, "no input provided. fuck off");
        return false;
    }
    process_input(net_user, array);
    for (size_t i = 0; array[i] != NULL; i++)
        free(array[i]);
    free(array);
    return true;
}
