/*
** EPITECH PROJECT, 2020
** epitech-myteams
** File description:
** login
*/

#include "server.h"

static user_info_t *find_user(my_teams_t *global_teams, char *username_to_find)
{
    TAILQ_FOREACH(
        global_teams->users, &global_teams->user_info_head, next_users)
    {
        if (strcmp(global_teams->users->username, username_to_find) == 0) {
            return global_teams->users;
        }
    }
    return NULL;
}

static void set_user_online(user_info_t *user)
{
    if (user->online == false)
        user->online = true;
}

void cmd_login(net_user_t *user, char **args)
{
    my_teams_t *global_teams = get_global_teams(NULL);
    char *param_no_quotes = NULL;
    user_info_t *current_user = NULL;

    if (check_input_args(1, args, user->socket_fd) == false)
        return;
    param_no_quotes = remove_quotes(args[1]);
    current_user = find_user(global_teams, param_no_quotes);
    if (current_user == NULL)
        current_user = add_user(global_teams, param_no_quotes);
    free(param_no_quotes);
    add_instance(current_user, user->socket_fd);
    set_user_online(current_user);
    server_event_user_logged_in(current_user->user_uuid);
    user->user = current_user;
    client_response(user->socket_fd, "welcome to the server");
}
