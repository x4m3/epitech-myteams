/*
** EPITECH PROJECT, 2020
** epitech-myteams
** File description:
** cmd
*/

#include "cmd.h"

const cmd_t commands[] = {{"/help", &cmd_help, "show help"},
    {"/login", &cmd_login, "set username used by client"},
    {"/logout", &cmd_logout, "disconnect the client from server"},
    {"/users", &cmd_users, "get the list of all users that exist on server"},
    {"/user", &cmd_user, "get information about a user"},
    {"/send", &cmd_send, "send a message to a user"},
    {"/messages", &cmd_messages, "list all messages exchange with a user"},
    {"/subscribe", &cmd_subscribe, "subscribe to the event of a team"},
    {"/subscribed", &cmd_subscribed,
        "list all subscribed teams or list all users subscribed to a team"},
    {"/use", &cmd_use, "specify a context team/channel/thread"},
    {"/create", &cmd_create, "create the sub resource based on context"},
    {"/list", &cmd_list, "list all sub resources based on context"},
    {"/info", &cmd_info, "get info based on context"}, {NULL, NULL, NULL}};
