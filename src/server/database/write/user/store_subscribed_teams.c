/*
** EPITECH PROJECT, 2019
** name of the project
** File description:
** foo
*/

#include "server.h"

void store_subscribed_teams(user_info_t *user, FILE *output)
{
    TAILQ_FOREACH(
        user->uuid_subcribed, &user->my_teams_uuid_head, next_user_uuid)
    {
        fprintf(output, "SUBSCRIBED_TEAM=%s\n", user->uuid_subcribed->uuid);
        printf("user [%s] is subscribed to this team [%s]\n", user->user_uuid,
            user->uuid_subcribed->uuid);
    }
}
