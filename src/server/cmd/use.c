/*
** EPITECH PROJECT, 2020
** epitech-myteams
** File description:
** use
*/

#include "server.h"

static void store_team(
    my_teams_t *my_teams, char arg[UUID_STR_LEN], instance_t *instance)
{
    if (check_team_uuid(my_teams, arg) == true) {
        instance->where = W_TEAM;
        strcpy(instance->team_uuid, arg);
        client_response(instance->socket_fd, "switch to team");
    } else {
        client_response(instance->socket_fd, "this team uuid does't exist");
    }
}

static void store_channel(
    team_t *team, char arg[UUID_STR_LEN], instance_t *instance)
{
    if (check_channel_uuid(team, arg) == true) {
        instance->where = W_CHANNEL;
        strcpy(instance->channel_uuid, arg);
        client_response(instance->socket_fd, "switch to channel");
    } else {
        client_response(instance->socket_fd, "this channel uuid does't exist");
    }
}

static void store_thread(
    channel_t *channel, char arg[UUID_STR_LEN], instance_t *instance)
{
    if (check_thread_uuid(channel, arg) == true) {
        instance->where = W_THREAD;
        strcpy(instance->thread_uuid, arg);
        client_response(instance->socket_fd, "switch to thread");
    } else {
        client_response(instance->socket_fd, "this thread uuid does't exist");
    }
}

static void exec_use_params(
    int nb_args, net_user_t *user, my_teams_t *my_teams, char **arg)
{
    team_t *team = NULL;
    channel_t *channel = NULL;
    instance_t *instance = NULL;

    if (nb_args >= 1) {
        team = find_team(my_teams, arg[1]);
        instance = find_instance(user->user, user->socket_fd);
        if (instance == NULL)
            return client_response(user->socket_fd, "lubrisol");
        store_team(my_teams, arg[1], instance);
    }
    if (nb_args >= 2) {
        channel = find_channel(team, arg[2]);
        store_channel(team, arg[2], instance);
    }
    if (nb_args == 3) {
        store_thread(channel, arg[3], instance);
    }
}

void cmd_use(net_user_t *user, char **args)
{
    my_teams_t *global_teams = get_global_teams(NULL);
    int nb_args = get_number_params(args);

    if (nb_args == 0)
        return client_response(user->socket_fd, "not enougth args");
    if (check_input_args(nb_args, args, user->socket_fd) == false)
        return;
    exec_use_params(nb_args, user, global_teams, args);
}
