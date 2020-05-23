/*
** EPITECH PROJECT, 2020
** epitech-myteams
** File description:
** client_handle
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "server.h"
#include "cmd.h"

static void process_input(net_user_t *net_user, char **input)
{
    size_t i = 0;

    for (size_t j = 0; input[j]; j++)
        printf("array[%zu]: [%s]\n", j, input[j]);
    if (input[0] == NULL) {
        // TODO: return bad command
    }
    for (; commands[i].name != NULL; i++) {
        if (strcmp(commands[i].name, input[0]) == 0)
            break;
    }
    if (commands[i].name == NULL) {
        // TODO: return bad command
    } else
        (commands[i].func)(net_user, input);
}

bool client_handle(net_user_t *net_user)
{
    char *buffer = NULL;
    char **array = client_input(net_user->input, buffer);

    if (array == NULL)
        return false;
    process_input(net_user, array);
    // dprintf(net_user->socket_fd, "okay\n");
    free(array);
    free(buffer);
    return true;
}
