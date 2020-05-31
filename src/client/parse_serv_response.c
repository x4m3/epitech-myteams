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
    cmd->c = (strcmp(cmd->cmd, "/login") == 0) ? (LOGIN) : (cmd->c);
    cmd->c = (strcmp(cmd->cmd, "/logout") == 0) ? (LOGOUT) : (cmd->c);
    cmd->c = (strcmp(cmd->cmd, "/help") == 0) ? (HELP) : (cmd->c);
    cmd->c = (strcmp(cmd->cmd, "/users") == 0) ? (USERS) : (cmd->c);
    cmd->c = (strcmp(cmd->cmd, "/user") == 0) ? (USER) : (cmd->c);
    cmd->c = (strcmp(cmd->cmd, "/send") == 0) ? (SEND) : (cmd->c);
    cmd->c = (strcmp(cmd->cmd, "/messages") == 0) ? (MESSAGES) : (cmd->c);
    cmd->c = (strcmp(cmd->cmd, "/subscribe") == 0) ? (SUBSCRIBE) : (cmd->c);
    cmd->c = (strcmp(cmd->cmd, "/subscribed") == 0) ? (SUBSCRIBED) : (cmd->c);
    cmd->c = (strcmp(cmd->cmd, "/unsubscribe") == 0) ? (UNSUBSCRIBE) : (cmd->c);
    cmd->c = (strcmp(cmd->cmd, "/use") == 0) ? (USE) : (cmd->c);
    cmd->c = (strcmp(cmd->cmd, "/create") == 0) ? (CREATE) : (cmd->c);
    cmd->c = (strcmp(cmd->cmd, "/list") == 0) ? (LIST) : (cmd->c);
    cmd->c = (strcmp(cmd->cmd, "/info") == 0) ? (INFO) : (cmd->c);
}

static void call_lib_function(command_t *cmd)
{
    switch (cmd->c)
    {
    case LOGIN:
        client_event_loggedin(cmd->args[0], cmd->args[1]);
        break;
    case LOGOUT:
        client;
    default:
        break;
    }
}

void parse_args_from_response(char *response, command_t *cmd)
{
    if ((cmd->args[0] = strtok(response, ",")) == NULL) {
        return;
    } else {
        for (size_t i = 1; i < 6 && (cmd->args[i] = strtok(NULL, ",") != NULL);
        i++);
    }
    attribute_cmd(cmd);
    if (cmd->c == NONE)
        return;
    call_lib_function(cmd);
}