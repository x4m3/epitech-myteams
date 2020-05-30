/*
** EPITECH PROJECT, 2020
** epitech-myteams
** File description:
** create
*/

#include "server.h"

static void create_team(
    my_teams_t *global_teams, net_user_t *user, char **args)
{
    char *name = args[1];
    char *desc = args[2];

    if (check_input_args(2, args, user->socket_fd) == false)
        return;
    add_team(name, desc, global_teams);
    client_response(user->socket_fd, "team created");
}

static void create_channel(
    my_teams_t *global_teams, net_user_t *user, char **args)
{
    char *title = args[1];
    char *desc = args[2];

    if (check_input_args(2, args, user->socket_fd) == false)
        return;
    add_channel(title, desc, global_teams->list_of_team);
    client_response(user->socket_fd, "thread created");
}

static void create_thread(
    my_teams_t *global_teams, net_user_t *user, char **args)
{
    char *author = args[1];
    char *title = args[2];
    char *msg = args[3];

    if (check_input_args(3, args, user->socket_fd) == false)
        return;
    add_thread(
        author, title, msg, global_teams->list_of_team->list_of_channel);
    client_response(user->socket_fd, "reply created");
}

static void create_reply(
    my_teams_t *global_teams, net_user_t *user, char **args)
{
    char *author = args[1];
    char *msg = args[2];

    if (check_input_args(2, args, user->socket_fd) == false)
        return;
    add_reply(author, msg,
        global_teams->list_of_team->list_of_channel->list_of_thread);
    client_response(user->socket_fd, "channel created");
}

void cmd_create(net_user_t *user, char **args)
{
    my_teams_t *global_teams = get_global_teams(NULL);

    if (user->user->list_of_instance->where == GLOBAL)
        return create_team(global_teams, user, args);
    if (user->user->list_of_instance->where == TEAM)
        return create_channel(global_teams, user, args);
    if (user->user->list_of_instance->where == CHANNEL)
        return create_thread(global_teams, user, args);
    if (user->user->list_of_instance->where == THREAD)
        return create_reply(global_teams, user, args);
    return client_response(user->socket_fd,
        "congrats you have won a prize for triggering the impossible");
}
