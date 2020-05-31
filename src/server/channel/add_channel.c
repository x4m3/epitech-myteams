/*
** EPITECH PROJECT, 2019
** name of the project
** File description:
** foo
*/

#include "server.h"

channel_t *add_channel(char title[MAX_NAME_LENGTH],
    char description[MAX_DESCRIPTION_LENGTH], team_t *team)
{
    uuid_t new_uuid_bin;

    if ((team->list_of_channel = malloc(sizeof(channel_t))) == NULL)
        return NULL;
    memset(team->list_of_channel, 0, sizeof(channel_t));
    uuid_generate_random(new_uuid_bin);
    uuid_unparse(new_uuid_bin, team->list_of_channel->channel_uuid);
    strcpy(team->list_of_channel->description, description);
    strcpy(team->list_of_channel->title, title);
    init_thread(team->list_of_channel);
    TAILQ_INSERT_HEAD(
        &team->channel_head, team->list_of_channel, next_channel);
    printf("add new team: [%s] [%s]\n", team->list_of_channel->title,
        team->list_of_channel->description);
    return team->list_of_channel;
}
