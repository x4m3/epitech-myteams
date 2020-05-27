/*
** EPITECH PROJECT, 2020
** epitech-myteams
** File description:
** login
*/

#include "server.h"

/**
** remove the quotes from a string
** @param source
** @return
**
** malloc: length of orig string - 2 (the 2 quotes)
**
** we *ASSUME* that the first quote is at position [0]
** and the last one is that position [strlen]
*/
static char *remove_quotes(const char *source)
{
    size_t i = strlen(source) - 2;
    char *str = malloc(sizeof(char) * (i + 1));

    if (str == NULL)
        return NULL;
    source++;
    strncpy(str, source, i);
    str[i] = 0;
    return str;
}

void cmd_login(net_user_t *user, char **args)
{
    my_teams_t *global_teams = get_global_teams(NULL);
    char *param_no_quotes = NULL;
    bool found = false;
    user_info_t *current_user = NULL;

    if (check_input_args(1, args, user->socket_fd) == false)
        return;
    param_no_quotes = remove_quotes(args[1]);
    printf("param no quotes: [%s]\n", param_no_quotes);
    TAILQ_FOREACH(
        global_teams->users, &global_teams->user_info_head, next_users)
    {
        if (strcmp(global_teams->users->username, param_no_quotes) == 0) {
            found = true;
            current_user = global_teams->users;
            break;
        }
    }
    if (found == false) {
        add_user(global_teams, param_no_quotes);
        current_user = (user_info_t *) global_teams->user_info_head.tqh_last;
    }
    add_instance(current_user, user->socket_fd);
    if (current_user->online == false)
        current_user->online = true;
    server_event_user_logged_in(current_user->user_uuid);
    client_response(user->socket_fd, "welcome to the server");
}
