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
    char *arg_to_send = NULL;

    if (check_input_args(2, args, user->socket_fd) == false)
        return;
    global_teams->list_of_team = add_team(name, desc, global_teams);
    server_event_team_created(
        global_teams->list_of_team->team_uuid, name, user->user->user_uuid);
    arg_to_send = concat_args_to_cli(
        global_teams->list_of_team->team_uuid, name, desc, NULL);
    client_response(user->socket_fd, arg_to_send);
    free(arg_to_send);
}

static void create_channel(
    my_teams_t *global_teams, net_user_t *user, char **args)
{
    char *title = args[1];
    char *desc = args[2];
    instance_t *instance = find_instance(user->user, user->socket_fd);
    char *arg_to_send = NULL;

    if (check_input_args(2, args, user->socket_fd) == false)
        return;
    global_teams->list_of_team = find_team(global_teams, instance->team_uuid);
    global_teams->list_of_team->list_of_channel =
        add_channel(title, desc, global_teams->list_of_team);
    server_event_channel_created(global_teams->list_of_team->team_uuid,
        global_teams->list_of_team->list_of_channel->channel_uuid, title);
    arg_to_send = concat_args_to_cli(
        global_teams->list_of_team->list_of_channel->channel_uuid, title, desc,
        NULL);
    client_response(user->socket_fd, arg_to_send);
    free(arg_to_send);
}

static void create_thread(
    my_teams_t *global_teams, net_user_t *user, char **args)
{
    char *author = args[1];
    char *title = args[2];
    char *msg = args[3];
    instance_t *instance = find_instance(user->user, user->socket_fd);

    if (check_input_args(3, args, user->socket_fd) == false)
        return;
    global_teams->list_of_team = find_team(global_teams, instance->team_uuid);
    global_teams->list_of_team->list_of_channel =
        find_channel(global_teams->list_of_team, instance->channel_uuid);
    add_thread(
        author, title, msg, global_teams->list_of_team->list_of_channel);
    server_event_thread_created(global_teams->list_of_team->team_uuid,
        global_teams->list_of_team->list_of_channel->channel_uuid,
        global_teams->list_of_team->list_of_channel->list_of_thread
            ->thread_uuid,
        title);
    send_thread_event_creation(global_teams, author, msg, user);
}

static void create_reply(
    my_teams_t *global_teams, net_user_t *user, char **args)
{
    char *author = args[1];
    char *msg = args[2];
    instance_t *instance = find_instance(user->user, user->socket_fd);

    if (check_input_args(2, args, user->socket_fd) == false)
        return;
    global_teams->list_of_team = find_team(global_teams, instance->team_uuid);
    global_teams->list_of_team->list_of_channel =
        find_channel(global_teams->list_of_team, instance->channel_uuid);
    global_teams->list_of_team->list_of_channel->list_of_thread = find_thread(
        global_teams->list_of_team->list_of_channel, instance->thread_uuid);
    add_reply(author, msg,
        global_teams->list_of_team->list_of_channel->list_of_thread);
    server_event_thread_new_message(global_teams->list_of_team->list_of_channel
                                        ->list_of_thread->thread_uuid,
        user->user->user_uuid, msg);
}

void cmd_create(net_user_t *user, char **args)
{
    my_teams_t *global_teams = get_global_teams(NULL);

    if (user->user->list_of_instance->where == W_GLOBAL)
        return create_team(global_teams, user, args);
    if (user->user->list_of_instance->where == W_TEAM)
        return create_channel(global_teams, user, args);
    if (user->user->list_of_instance->where == W_CHANNEL)
        return create_thread(global_teams, user, args);
    if (user->user->list_of_instance->where == W_THREAD)
        return create_reply(global_teams, user, args);
    return client_response(user->socket_fd,
        "congrats you have won a prize for triggering the impossible");
}
