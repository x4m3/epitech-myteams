/*
** EPITECH PROJECT, 2020
** epitech-myteams
** File description:
** client
*/

#include "client.h"

static void attribute_cmd(command_t *cmd)
{
    if (!cmd->cmd)
        return;
    cmd->c = NONE;
    cmd->c = (strncmp(cmd->cmd, "/login", 6) == 0) ? (LOGIN) : (cmd->c);
    cmd->c = (strncmp(cmd->cmd, "/logout", 7) == 0) ? (LOGOUT) : (cmd->c);
    cmd->c = (strncmp(cmd->cmd, "/help", 5) == 0) ? (HELP) : (cmd->c);
    cmd->c = (strcmp(cmd->cmd, "/users") == 0) ? (USERS) : (cmd->c);
    cmd->c = (strcmp(cmd->cmd, "/user") == 0) ? (USER) : (cmd->c);
    cmd->c = (strncmp(cmd->cmd, "/send", 5) == 0) ? (SEND) : (cmd->c);
    cmd->c = (strncmp(cmd->cmd, "/messages", 9) == 0) ? (MESSAGES) : (cmd->c);
    cmd->c = (strcmp(cmd->cmd, "/subscribe") == 0) ? (SUBSCRIBE) : (cmd->c);
    cmd->c = (strcmp(cmd->cmd, "/subscribed") == 0) ? (SUBSCRIBED) : (cmd->c);
    cmd->c = (strncmp(cmd->cmd, "/unsubscribe", 12) == 0) ? (UNSUB) : (cmd->c);
    cmd->c = (strcmp(cmd->cmd, "/use") == 0) ? (USE) : (cmd->c);
    cmd->c = (strncmp(cmd->cmd, "/create", 7) == 0) ? (CREATE) : (cmd->c);
    cmd->c = (strncmp(cmd->cmd, "/list", 5) == 0) ? (LIST) : (cmd->c);
    cmd->c = (strncmp(cmd->cmd, "/info", 5) == 0) ? (INFO) : (cmd->c);
}

static void call_lib_function(command_t *cmd)
{
    switch (cmd->c) {
        case LOGIN: client_event_loggedin(cmd->args[0], cmd->args[1]); break;
        case LOGOUT: client_event_loggedout(cmd->args[0], cmd->args[1]); break;
        case USER:
            client_print_user(cmd->args[0], cmd->args[1], atoi(cmd->args[2]));
            break;
        default: break;
    }
}

void parse_args_from_response(char *response, command_t *cmd)
{
    if ((cmd->args[0] = strtok(response, ",")) == NULL) {
        return;
    } else {
        for (size_t i = 1;
             i < 6 && (cmd->args[i] = strtok(NULL, ",")) != NULL;) {
            i++;
        }
    }
    attribute_cmd(cmd);
    if (cmd->c == NONE)
        return;
    call_lib_function(cmd);
    for (size_t i = 0; i < 6; i++)
        cmd->args[i] = NULL;
}
