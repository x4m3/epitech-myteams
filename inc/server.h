/*
** EPITECH PROJECT, 2020
** day02
** File description:
** foo
*/

#ifndef SERVER_H_
#define SERVER_H_

#include <netinet/in.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/queue.h>
#include <sys/select.h>
#include <uuid/uuid.h>
#include "myteams.h"
#include "unistd.h"
#include "logging_server.h"
#include <bits/types/time_t.h>

enum where_e { GLOBAL = 0, TEAM, CHANNEL, THREAD };

typedef struct instance_t {
    int socket_fd;
    enum where_e where;
    char team_uuid[UUID_STR_LEN];
    char channel_uuid[UUID_STR_LEN];
    char thread_uuid[UUID_STR_LEN];
    TAILQ_ENTRY(instance_t) next_instance;
} instance_t;

typedef struct message_t {
    char author[UUID_STR_LEN];
    time_t creation_date;
    char body_message[MAX_BODY_LENGTH];
    TAILQ_ENTRY(message_t) next_message;
} message_t;

typedef struct thread_t {
    char author[MAX_BODY_LENGTH];
    char thread_uuid[UUID_STR_LEN];
    time_t creation_date;
    char title[MAX_DESCRIPTION_LENGTH];
    char message[MAX_BODY_LENGTH];
    TAILQ_ENTRY(thread_t) next_thread;
    message_t *list_of_message;
    TAILQ_HEAD(, message_t) message_head;
} thread_t;

typedef struct channel_t {
    char title[MAX_NAME_LENGTH];
    char channel_uuid[UUID_STR_LEN];
    char description[MAX_DESCRIPTION_LENGTH];
    thread_t *list_of_thread;
    TAILQ_ENTRY(channel_t) next_channel;
    TAILQ_HEAD(, thread_t) thread_head;
} channel_t;

typedef struct myteams_uuid_t {
    char uuid[UUID_STR_LEN];
    TAILQ_ENTRY(myteams_uuid_t) next_user_uuid;
} myteams_uuid_t;

typedef struct team_t {
    char name[MAX_NAME_LENGTH];
    char team_uuid[UUID_STR_LEN];
    char description[MAX_DESCRIPTION_LENGTH];
    myteams_uuid_t *uuid_subcribed;
    TAILQ_HEAD(, myteams_uuid_t) my_teams_uuid_head;
    channel_t *list_of_channel;
    TAILQ_HEAD(, channel_t) channel_head;
    TAILQ_ENTRY(team_t) next_team;
} team_t;

typedef struct user_info_t {
    char username[MAX_NAME_LENGTH];
    char user_uuid[UUID_STR_LEN];
    instance_t *list_of_instance;
    TAILQ_HEAD(, instance_t) instance_head;
    bool online;
    TAILQ_ENTRY(user_info_t) next_users;
} user_info_t;

typedef struct {
    user_info_t *users;
    TAILQ_HEAD(, user_info_t) user_info_head;
    team_t *list_of_team;
    TAILQ_HEAD(, team_t) team_head;
    message_t *list_of_message;
    TAILQ_HEAD(, message_t) message_head;
} my_teams_t;

typedef struct {
    user_info_t *user;
    int socket_fd;
    FILE *input;
} net_user_t;

typedef struct {
    int socket_fd;
    struct sockaddr_in addr;
    fd_set active;
    fd_set read;
    int max_fd;
    net_user_t *net_users;
    my_teams_t *my_teams;
} server_t;

server_t *server_init(char **av);
void server_loop(server_t *server);
bool client_init(server_t *server);
void client_delete(net_user_t *net_user);
bool client_handle(net_user_t *net_user);
char **client_input(FILE *input, char *buffer);
void client_response(int output, const char *str);

/* proto init structure */
my_teams_t *init_my_teams(void);
team_t *init_team(my_teams_t *my_teams);
channel_t *init_channel(team_t *team);
thread_t *init_thread(channel_t *channel);
message_t *init_message(thread_t *thread);
instance_t *init_instance(user_info_t *user);
myteams_uuid_t *init_myteams_uuid(team_t *team);
user_info_t *init_user_info(my_teams_t *myteam);

/* proto delete structure */
void delete_myteams(my_teams_t *myteams);
void delete_team(my_teams_t *my_team);
void delete_channel(team_t *team);
void delete_thread(channel_t *channel);
void delete_message(void *thread, char c);
void delete_all_instances(user_info_t *user);
bool delete_one_instance(user_info_t *user, int socket_fd);
void delete_user_info(my_teams_t *myteams);
void delete_myteams_uuid(team_t *team);

bool check_input_args(size_t nb, char **args, int socket_fd);
char *remove_quotes(const char *source);

my_teams_t *get_global_teams(my_teams_t *new);
user_info_t *add_user(my_teams_t *myTeams, char *username);
instance_t *add_instance(user_info_t *user, int socket_id);

void list_user(my_teams_t *myTeams, int socket_user);
void list_team(my_teams_t *myTeams, int socket_user);
void list_users_subscribed(team_t *team, int socket_user);
myteams_uuid_t *add_team_uuid(team_t *team);

#endif // SERVER_H_
