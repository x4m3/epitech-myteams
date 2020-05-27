/*
** EPITECH PROJECT, 2019
** name of the project
** File description:
** foo
*/

#include "server.h"

team_t *add_team(
    char name[MAX_NAME_LENGTH], char description[MAX_DESCRIPTION_LENGTH])
{
    team_t *new_team;
    uuid_t new_uuid_bin;

    if ((new_team = malloc(sizeof(team_t))) == NULL)
        return NULL;
    uuid_generate_random(new_uuid_bin);
    uuid_unparse(new_uuid_bin, new_team->team_uuid);
    strcpy(new_team->description, description);
    strcpy(new_team->name, name);

}
