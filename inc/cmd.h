/*
** EPITECH PROJECT, 2020
** epitech-myteams
** File description:
** cmd
*/

#ifndef CMD_H_
#define CMD_H_

#include "server.h"

typedef struct {
    char *name;
    void (*func)(net_user_t *, char **);
    char *help;
} cmd_t;

extern const cmd_t commands[];

void cmd_help(net_user_t *user, char **args);
void cmd_login(net_user_t *user, char **args);
void cmd_logout(net_user_t *user, char **args);
void cmd_users(net_user_t *user, char **args);
void cmd_user(net_user_t *user, char **args);
void cmd_send(net_user_t *user, char **args);
void cmd_messages(net_user_t *user, char **args);
void cmd_subscribe(net_user_t *user, char **args);
void cmd_subscribed(net_user_t *user, char **args);
void cmd_use(net_user_t *user, char **args);
void cmd_create(net_user_t *user, char **args);
void cmd_list(net_user_t *user, char **args);
void cmd_info(net_user_t *user, char **args);

#endif /* !CMD_H_ */
