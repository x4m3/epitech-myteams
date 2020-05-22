/*
** EPITECH PROJECT, 2020
** day02
** File description:
** foo
*/

#ifndef SERVER_H_
#define SERVER_H_

#include <stdbool.h>
#include <sys/queue.h>
#include <uuid/uuid.h>
#include "myteams.h"
#include <bits/types/time_t.h>

enum where_e { GLOBAL = 0, TEAM, CHANNEL, THREAD };

typedef struct {
    int socket_id;
    enum where_e where;
    char team_uuid[UUID_STR_LEN];
    char channel_uuid[UUID_STR_LEN];
    char thread_uuid[UUID_STR_LEN];
} instance_t;

typedef struct {
    char author[UUID_STR_LEN];
    time_t creation_date;
    char body_message[MAX_BODY_LENGTH];
} message_t;

typedef struct {
    char author[MAX_BODY_LENGTH];
    char thread_uuid[UUID_STR_LEN];
    time_t creation_date;
    char title[MAX_DESCRIPTION_LENGTH];
    char message[MAX_BODY_LENGTH];
    LIST_ENTRY(message_t) next_message;
} thread_t;

typedef struct {
    char title[MAX_NAME_LENGTH];
    char channel_uuid[UUID_STR_LEN];
    char description[MAX_DESCRIPTION_LENGTH];
    LIST_ENTRY(thread_t) next_thread;
} channel_t;

typedef struct {
    char uuid[UUID_STR_LEN];
} myteams_uuid_t;

typedef struct {
    char name[MAX_NAME_LENGTH];
    char team_uuid[UUID_STR_LEN];
    char description[MAX_DESCRIPTION_LENGTH];
    LIST_ENTRY(channel_t) next_channel;
    LIST_ENTRY(myteams_uuid_t) next_user_uuid;
} team_t;

typedef struct {
    char username[MAX_NAME_LENGTH];
    char user_uuid[UUID_STR_LEN];
    instance_t *list_of_instance;
    bool is_loggedin;
    LIST_ENTRY(team_t) next_team;
} user_info_t;

typedef struct {
    LIST_ENTRY(user_info_t) next_user;
    LIST_ENTRY(team_t) next_team;
    LIST_ENTRY(message_t) next_message;
} my_teams_t;
#endif // SERVER_H_
