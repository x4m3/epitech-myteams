/*
** EPITECH PROJECT, 2019
** name of the project
** File description:
** foo
*/

#include "server.h"

channel_t *init_channel(team_t *team)
{
    TAILQ_INIT(&team->channel_head);
    return team->list_of_channel;
}
