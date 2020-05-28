/*
** EPITECH PROJECT, 2020
** epitech-myteams
** File description:
** client_delete
*/

#include "server.h"

void client_delete(net_user_t *net_user)
{
    net_user->user = NULL;
    fclose(net_user->input);
    close(net_user->socket_fd);
    net_user->socket_fd = 0;
}
