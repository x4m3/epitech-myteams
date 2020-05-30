/*
** EPITECH PROJECT, 2020
** epitech-myteams
** File description:
** use
*/

#include "server.h"

static int get_number_params(char **args)
{
    int number_params = 0;

    for (size_t i = 0; args[i] != NULL; i++)
        number_params++;
    return number_params - 1;
}

static void store_team(
    my_teams_t *my_teams, char arg[UUID_STR_LEN], net_user_t *user)
{
    if (check_team_uuid(my_teams, arg) == true) {
        user->user->list_of_instance->where = W_TEAM;
        strcpy(user->user->list_of_instance->team_uuid, arg);
    } else {
        client_response(user->socket_fd, "this team uuid does't exist");
    }
}

static void store_channel(
    team_t *team, char arg[UUID_STR_LEN], net_user_t *user)
{
    if (check_channel_uuid(team, arg) == true) {
        user->user->list_of_instance->where = W_CHANNEL;
        strcpy(user->user->list_of_instance->channel_uuid, arg);
    } else {
        client_response(user->socket_fd, "this channel uuid does't exist");
    }
}

static void store_thread(
    channel_t *channel, char arg[UUID_STR_LEN], net_user_t *user)
{
    if (check_thread_uuid(channel, arg) == true) {
        user->user->list_of_instance->where = W_THREAD;
        strcpy(user->user->list_of_instance->thread_uuid, arg);
    } else {
        client_response(user->socket_fd, "this thread uuid does't exist");
    }
}

static void exec_use_params(
    int nb_args, net_user_t *user, my_teams_t *my_teams, char **arg)
{
    if (nb_args >= 1)
        store_team(my_teams, arg[1], user);
    if (nb_args >= 2) {
        store_channel(user->user->list_of_instance->)
    }
    if (nb_args == 3) {
        //store_thread(my_teams, arg[1], user);

    }
}

void cmd_use(net_user_t *user, char **args)
{
    my_teams_t *global_teams = get_global_teams(NULL);
    int nb_args = get_number_params(args);

    if (check_input_args(nb_args, args, user->socket_fd) == false)
        return;
    exec_use_params(nb_args, user, global_teams, args);
}
