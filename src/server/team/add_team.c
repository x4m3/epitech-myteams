/*
** EPITECH PROJECT, 2019
** name of the project
** File description:
** foo
*/

#include "server.h"

team_t *add_team(char name[MAX_NAME_LENGTH],
    char description[MAX_DESCRIPTION_LENGTH], my_teams_t *myTeams)
{
    uuid_t new_uuid_bin;

    if ((myTeams->list_of_team = malloc(sizeof(team_t))) == NULL)
        return NULL;
    uuid_generate_random(new_uuid_bin);
    uuid_unparse(new_uuid_bin, myTeams->list_of_team->team_uuid);
    strcpy(myTeams->list_of_team->description, description);
    strcpy(myTeams->list_of_team->name, name);
    TAILQ_INSERT_HEAD(&myTeams->team_head, myTeams->list_of_team, next_team);
    init_myteams_uuid(myTeams->list_of_team);
    printf("add new team: [%s] [%s] [%s]\n", myTeams->list_of_team->name,
        myTeams->list_of_team->description, myTeams->list_of_team->team_uuid);

    return myTeams->list_of_team;
}
