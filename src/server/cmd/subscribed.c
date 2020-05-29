/*
** EPITECH PROJECT, 2020
** epitech-myteams
** File description:
** subscribed
*/

#include "server.h"

bool is_user_subscribe(team_t *team, char author[UUID_STR_LEN])
{
    bool is_register = false;

    TAILQ_FOREACH(
        team->uuid_subcribed, &team->my_teams_uuid_head, next_user_uuid)
    {
        printf("%s\n", author);
        printf("dans la boucle %s\n", team->uuid_subcribed->uuid);
        if (strcmp(team->uuid_subcribed->uuid, author) == 0) {
            is_register = true;
            break;
        }
    }
    return is_register;
}

void list_subcribed_team(
    my_teams_t *myTeams, char author[UUID_STR_LEN], int socket_user)
{
    TAILQ_FOREACH(myTeams->list_of_team, &myTeams->team_head, next_team)
    {
        if (is_user_subscribe(myTeams->list_of_team, author) == true)
            client_response(socket_user, myTeams->list_of_team->team_uuid);
    }
}

void list_all_user_in_team(
    my_teams_t *myTeams, char team_uuid[UUID_STR_LEN], int socket_user)
{
    TAILQ_FOREACH(myTeams->list_of_team, &myTeams->team_head, next_team)
    {
        if (strcmp(myTeams->list_of_team->team_uuid, team_uuid) == 0) {
            list_users_subscribed(myTeams->list_of_team, socket_user);
            return;
        }
    }
    client_response(socket_user, "this team_uuid ins't exist");
}

void cmd_subscribed(net_user_t *user, char **args)
{
    my_teams_t *global_teams = get_global_teams(NULL);
    char *param_no_quotes = NULL;

    if (args[1] == NULL)
        list_subcribed_team(
            global_teams, user->user->user_uuid, user->socket_fd);
    else {
        param_no_quotes = remove_quotes(args[1]);
        list_all_user_in_team(global_teams, param_no_quotes, user->socket_fd);
    }
    // client_response(user->socket_fd, "subscribed");
}
