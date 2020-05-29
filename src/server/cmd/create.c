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
    char *name_no_quotes = NULL;
    char *desc_no_quotes = NULL;

    if (check_input_args(2, args, user->socket_fd) == false)
        return;
    name_no_quotes = remove_quotes(args[1]);
    desc_no_quotes = remove_quotes(args[2]);
    add_team(name_no_quotes, desc_no_quotes, global_teams);
    free(name_no_quotes);
    free(desc_no_quotes);
    client_response(user->socket_fd, "team created");
}

static void create_channel(
    my_teams_t *global_teams, net_user_t *user, char **args)
{
    char *title_no_quotes = NULL;
    char *desc_no_quotes = NULL;

    if (check_input_args(2, args, user->socket_fd) == false)
        return;
    title_no_quotes = remove_quotes(args[1]);
    desc_no_quotes = remove_quotes(args[2]);
    add_channel(title_no_quotes, desc_no_quotes, global_teams->list_of_team);
    free(title_no_quotes);
    free(desc_no_quotes);
    client_response(user->socket_fd, "thread created");
}

static void create_thread(
    my_teams_t *global_teams, net_user_t *user, char **args)
{
    char *author_no_quotes = NULL;
    char *title_no_quotes = NULL;
    char *message_no_quotes = NULL;

    if (check_input_args(3, args, user->socket_fd) == false)
        return;
    author_no_quotes = remove_quotes(args[1]);
    title_no_quotes = remove_quotes(args[2]);
    message_no_quotes = remove_quotes(args[3]);
    add_thread(author_no_quotes, title_no_quotes, message_no_quotes,
        global_teams->list_of_team->list_of_channel);
    free(title_no_quotes);
    free(author_no_quotes);
    free(message_no_quotes);
    client_response(user->socket_fd, "reply created");
}

static void create_reply(
    my_teams_t *global_teams, net_user_t *user, char **args)
{
    char *author_no_quotes = NULL;
    char *message_no_quotes = NULL;

    if (check_input_args(2, args, user->socket_fd) == false)
        return;
    author_no_quotes = remove_quotes(args[1]);
    message_no_quotes = remove_quotes(args[2]);
    add_reply(author_no_quotes, message_no_quotes,
        global_teams->list_of_team->list_of_channel->list_of_thread);
    free(author_no_quotes);
    free(message_no_quotes);
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
