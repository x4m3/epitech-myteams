/*
** EPITECH PROJECT, 2019
** name of the project
** File description:
** foo
*/

#include "server.h"

team_t *add_team(char name[MAX_NAME_LENGTH],
    char description[MAX_DESCRIPTION_LENGTH], my_teams_t *my_teams)
{
    uuid_t new_uuid_bin;

    if ((my_teams->list_of_team = malloc(sizeof(team_t))) == NULL)
        return NULL;
    memset(my_teams->list_of_team, 0, sizeof(team_t));
    uuid_generate_random(new_uuid_bin);
    uuid_unparse(new_uuid_bin, my_teams->list_of_team->team_uuid);
    strcpy(my_teams->list_of_team->description, description);
    strcpy(my_teams->list_of_team->name, name);
    my_teams->list_of_team->list_of_channel =
        init_channel(my_teams->list_of_team);
    my_teams->list_of_team->uuid_subcribed =
        init_myteams_uuid(my_teams->list_of_team);
    TAILQ_INSERT_HEAD(&my_teams->team_head, my_teams->list_of_team, next_team);
    printf("add new team: [%s] [%s] [%s]\n", my_teams->list_of_team->name,
        my_teams->list_of_team->description,
        my_teams->list_of_team->team_uuid);
    return my_teams->list_of_team;
}
