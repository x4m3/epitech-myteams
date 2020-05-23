/*
** EPITECH PROJECT, 2020
** epitech-myteams
** File description:
** client_handle
*/

#include <stdio.h>
#include <stdlib.h>
#include "server.h"

bool client_handle(net_user_t *net_user)
{
    char *input = NULL;
    size_t input_len = 0;
    ssize_t getline_ret = getline(&input, &input_len, net_user->input);

    if (getline_ret == -1)
        return false;
    printf("got input from client: [%s]\n", input);
    dprintf(net_user->socket_fd, "%s", input);
    free(input);
    return true;
}
